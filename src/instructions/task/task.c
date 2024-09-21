/**
 * @file task.c
 * @author  buttfa (1662332017@qq.com)
 * @brief CCC compiler task module
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <task.h>


/**
 * @brief The conditional function of the task
 * 
 * @param argc Number of parameters passed to CCC
 * @param argv Parameters passed to CCC
 * @return true The parameters conform to the task format
 * @return false The parameters do not conform to the task format
 */
bool cdt_task(int argc, char** argv) {
    if (argc == 1 || argc == 2 || argc == 3) {
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Determine whether it is a shell task, 
 *        and if so, execute the shell task.
 * 
 * @param ccc_section Sections that need to be judged
 */
static void isShellTask(section *ccc_section) {
    if (strlen(ccc_section->name) > 7 && strncmp(ccc_section->name, "<shell>", 7) == 0) {
        // Change the name of the section
        char* task_name = strdup(ccc_section->name+7);
        free(ccc_section->name);
        ccc_section->name = task_name;

        // Execute shell tasks
        for (int i = 0; i < ccc_section->kvp_num; i++) {
            // If the key is NULL or starts with null, no key is output
            if (strlen(ccc_section->kvps[i]->key)>=6 && (strncmp(ccc_section->kvps[i]->key, "(NULL)",6)==0||strncmp(ccc_section->kvps[i]->key, "(null)",6)==0)){

            } else {
                printf("%s\n", ccc_section->kvps[i]->key);
            }
            system(ccc_section->kvps[i]->value);
        }
    }
}

/**
 * @brief Determine whether it is a compilation task, 
 *        and if so, execute the compilation task.
 * 
 * @param ccc_section Sections that need to be judged
 */
static void isCompileTask(section *ccc_section) {
    struct COMPILE_TASK task;
    if (strlen(ccc_section->name)>6 && strncmp(ccc_section->name, "<task>", 6) == 0) {
        // Change the name of the section
        char* task_name = strdup(ccc_section->name+6);
        free(ccc_section->name);
        ccc_section->name = task_name;

        // Execute compilation tasks
        task = parseCCCIni(ccc_section); // This function will generate a compileTask variable based on the information in the section 
                                         // and allocate memory for the pointers within it
        handTask(task); // This function executes the compilation task and releases the memory pointed 
                        // to by the pointer in the compileTask variable after completion.
    }
}

/**
 * @brief task function
 * 
 * @param argc Number of parameters passed to CCC
 * @param argv Parameters passed to CCC
 */
void task_func(int argc, char** argv) {
    char* ccc_file_path = "project.ccc";
    char* target_section_name = NULL;

    // Obtain the path of the .ccc file
    if (argc == 3) {
        ccc_file_path = argv[1];
        target_section_name = argv[2];
    }
    else if (argc == 2) {
        if (isFileWithSuffix(argv[1],".ccc"))
            ccc_file_path = argv[1];
        else
            target_section_name = argv[1];
    }
    else if (argc == 1) {
        
    }

    // If the file does not exist or is not a .ccc file
    if (access(ccc_file_path, F_OK)!=0 || !isFileWithSuffix(ccc_file_path,".ccc")) {
        printf("[CCC]The target file does not exist or does not have a. ccc suffix\n");
        goto end;
    }

    // Parse the .ccc file
    ini* ccc_ini = iniParseFile(ccc_file_path);
/* Dynamic Memory ccc_ini --^*/
    if (ccc_ini == NULL) {
        printf("[CCC]Failed to parse the .ccc file\n");
        goto end;
    }
    if (ccc_ini->section_num == 0) {
        printf("[CCC]The .ccc file does not contain any tasks\n");
        goto ini_release;
    }


    // Get target_section
    section* target_section = NULL;
    if (target_section_name == NULL &&  (
            (strlen(ccc_ini->sections[0]->name)>6 && strncmp(ccc_ini->sections[0]->name, "<task>", 6)==0)
            || (strlen(ccc_ini->sections[0]->name)>7 && strncmp(ccc_ini->sections[0]->name, "<shell>", 7)==0)
        )
    ) {
        target_section = ccc_ini->sections[0];
    }
        

    if (target_section_name != NULL ) {
        for (int i = 0; i < ccc_ini->section_num; i++) {
            if ((strlen(ccc_ini->sections[i]->name)>6 && strncmp(ccc_ini->sections[i]->name, "<task>", 6)==0 && strcmp(target_section_name, ccc_ini->sections[i]->name+6)==0)
            || (strlen(ccc_ini->sections[i]->name)>7 && strncmp(ccc_ini->sections[i]->name, "<shell>", 7)==0 && strcmp(target_section_name, ccc_ini->sections[i]->name+7)==0)) {
                target_section = ccc_ini->sections[i];
                break;
            }
        }
    }

    if (target_section == NULL) {
        printf("[CCC]The target task does not exist\n");
        goto ini_release;
    }

    // Justify whether it is a compilation task, if so, execute the compilation task
    isCompileTask(target_section);

    // Justify whether it is a shell task, if so, execute the shell task
    isShellTask(target_section);

ini_release:
    iniFree(ccc_ini);
/* Release memory ccc_ini --^ */
end:
    return;
}
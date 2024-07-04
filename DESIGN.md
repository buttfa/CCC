
```c
// 文件节点
struct file_node {
    char* file_path;
    struct file_node* next;
};


struct header_folder {
    char* folder_path;
    struct header_folder* next;
};
struct header_folder* header_folder_list;
char* header_folders;


struct reliance {
    char* file_path;

    int reliance_num;
    char** reliant_file;

    struct reliance* next;
};
struct reliance* reliance_list;
struct reliance* tartget_reliance;

char* obj_files;

struct file_node* sll_list;
char* sll_files;

struct file_node* dll_list;
char* dll_files;
```

## 工作原理
#### （一）获得头文件目录
##### 1. 遍历$(header_folder_path)和$(library_path)中的文件夹，找到包含.h文件的文件夹，确认路径不重复后为其创造header_folder结构体，并添加到header_folder_list链表中。（为了确保路径不重复，每次添加前都需要从头遍历head_folder_list链表，确认该路径不存在后才添加节点）
##### 2. 遍历header_folder_list链表，统计folder_path的总长度，计算header_folders应该分配的内存。
##### 3. 再次遍历header_folder_list链表，将每个节点的folder_path复制到header_folders中。

#### （二）计算依赖关系
##### 中间文件的依赖关系
##### 1. 遍历$(source_folder_path)和$(library_path)，找到.c/.cpp文件。
##### 2. 确保.c/.cpp路径不重复后，为.c/.cpp文件创建一个reliance并添加到reliance_list。（为了确保路径不重复，每次添加前都需要从头遍历reliance_list链表，确认该路径不存在后才添加节点）
##### 2.1 将.c/.cpp文件名前的路径替换为$(obj_path)，将后缀名替换为.o，将其写入file_path中。
##### 2.2 使用```gcc -M .c/.cpp -I header_folders```获得.c/.cpp依赖的头文件路径，计算这些头文件路径的个数，将该值+1写入reliance_num中。
##### 2.3 计算出char** reliant_file需要分配的空间（为reliance_num）。
##### 2.4 将.c/.cpp文件路径添加到reliant_file[0]。
##### 2.5 将头文件路径依次添加到*reliant_file中。


##### 目标的依赖关系
##### 1. target_reliance的file_path写入为$(output_file_path)/$(ccc_file_name)
##### 1. 遍历reliance_list的节点，计算节点数。
##### 2. 将节点数写入target_reliance的reliance_num中，并为char** reliant_files分配空间
##### 3. 再次遍历reliance_list的节点，将节点的file_path写入target_reliance.reliant_files中。

#### （三）获取中间文件组
##### 1. 遍历reliance_list的节点，计算其中file_path的长度和
##### 2. 根据file_path的长度和为obj_files分配空间。
##### 3. 再次遍历reliance_list的节点，将每个节点的file_path写入obj_files中。

#### （四）载入静态链接库文件
##### 1. 遍历(sll_folder_path)和(library_path)，找到.a文件。
##### 2. 确保.a文件路径不重复后，为.a创建一个file_node并添加到sll_list链表中。
##### 3. 遍历sll_list链表，统计file_path的长度，计算sll_files应该分配的内存。
##### 4. 再次遍历sll_list链表，将每个节点的file_path复制到sll_files中。

#### （五）载入动态链接库文件
##### 1. 遍历$(dll_folder_path)和$(library_path)，找到.so文件。
##### 2. 确保.so文件路径不重复后，为.so创建一个file_node并添加到dll_list链表中。
##### 3. 遍历dll_list链表，统计file_path的长度，计算dll_files应该分配的内存。
##### 4. 再次遍历dll_list链表，将每个节点的file_path复制到dll_files中。

#### （六）检查依赖
##### 1. 遍历reliance_list链表，检查每个reliance中的file是否需要更新。
##### 2. 如果reliance中的file需要更新，则执行```$(compiler) reliance.reliant_file[0] -o reliance.file_path -I header_folders $(compile_flags)```，其中reliance.reliant_file[0]为.o文件对应的.c/.cpp文件
##### 3. 遍历完整个reliance_list链表后，检查tartget_reliance是否需要更新，如果需要更新，则执行```$(linker) obj_files sll_files dll_files -o target_reliance->file_path $(link_flags)```
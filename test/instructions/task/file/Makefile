allTest: testsplitStringBySpace
	
testsplitStringBySpace:
	@echo "test splitStringBySpace function"
# 编译testsplitStringBySpace测试单元
	g++ -o testsplitStringBySpace testsplitStringBySpace.cpp ../../../../src/instructions/task/file.c  -lgtest -lgtest_main -pthread  -I /home/z/ccc/inc/instructions/task
# 执行测试
	./testsplitStringBySpace
# 删除测试文件
	rm testsplitStringBySpace

clean:
	rm testsplitStringBySpace
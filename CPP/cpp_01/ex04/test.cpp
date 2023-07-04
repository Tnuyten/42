#include <unistd.h>
#include <iostream>

int run_test(char** args) {
	pid_t pid = fork();
	if(pid == 0) {
		if(execve("./notsed", args, NULL) == -1) {
			perror("execve failed: ");
			return -1;
		}
	}
	return 0;
}

int main() {
	int num_tests = 8;

	std::string filenames[8] = {"a","b","_c","d","e","f","","empty"};

	std::string test1[2] = {"Lorem", ""};
	std::string test2[2] = {"Lorem ipsum", "qwertyuiop"};
	std::string test3[2] = {"m", "mmmmm"};
	std::string test4[2] = {"o", ".."};
	std::string test5[2] = {" ", ""};

	std::string test6[2] = {"", ""};
	std::string test7[2] = {"l", "sch"};
	std::string test8[2] = {"a", "b"};


	std::string *tests[8] = {test1, test2, test3, test4, test5, test6, test7, test8};

	for (int i = 0; i < num_tests; i++) {
		std::string filename = "testfiles/" + filenames[i];
		const char* argv[] = {"notsed", &filename[0], &tests[i][0][0], &tests[i][1][0], NULL};
		run_test((char**)argv);
	}
}
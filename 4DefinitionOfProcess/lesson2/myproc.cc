#include <iostream>
#include <unistd.h>
#include <stdlib.h>
using namespace std;
int main()
{
	pid_t id = fork();
	if (id == 0) { // child
		while (true) {
			cout << "child process running" << endl;
			sleep(2);
		}
	}
	else { // parent
		cout << "parent proccess sleeping" << endl;
		sleep(10);	
		exit(1);
	}

//	while (true) {
//		cout << "hello S+" << endl; //CPU等待进程输出内容
//	}
//	while (true) {
//		//死循环，一直占用CPU资源
//	}
//	while (1) {
//		sleep(10); //sleep即S状态
//		cout << "hello proc" << endl;
//	}
//	pid_t id = fork();
//	if (id == 0) { //child 
//		while (true) {
//			cout << "I am child  process, pid:" << getpid() << ", ppid:" << getppid() << endl;
//			sleep(1);
//		}	
//	}
//	else if (id > 0) { //parent 
//		while (true) {
//			cout << "I am parent process, pid:" << getpid() << ", ppid:" << getppid() << endl;
//			sleep(2);
//		}	
//	}
//	else { // fail
//		
//	}
//	cout << "hello proccess, " << "pid:" << getpid() << 
//				", parent ppid:" << getppid() << ", fork_ret:" << id  << endl;
	sleep(1);


	
	return 0;
}

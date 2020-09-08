#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

//Fork() is used for creating a new process(child process), which runs concurrently with the process that makes the fork() call(parent process).
//For 3 fork{} executions - 8 processes are created, because for every parent process it creates child process, and for every iteration every child process became parent process
// P------- P0
//      P1      P2
//    P3 P4   P5  P6   - overall 8 processes

//For 5 fork() executions - 32 processes are created.

int main(){
	int i;
	for(i=0;i<5;i++){
		fork();
	}
	sleep(5);
	return 0;
}


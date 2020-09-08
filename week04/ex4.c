#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <unistd.h>
//ex3 with parameter, we get all line and pass it to system
//  Error: something strange is going on! because  getline or sscanf
//  (on input or matching failure) could return EOF (-1) with no way
//  of telling what the problem was
//  source:ttps://stackoverflow.com/questions/33749471/c-getline-returns-1-before-eof
int main(void){
	int bytes_read;
    int size = 10;
    char *command;
	while(1){
		printf("> ");
		command = (char *)malloc (size);
		bytes_read = getline(&command, &size, stdin);
		if (bytes_read == -1){puts("Error: something strange is going on!");break;}
		if (strcmp(command, "exit\n")==0){break;}
		if (!fork()){
            system(command);
            return 0;
        }
        free(command);
	}
	puts("\n");
}

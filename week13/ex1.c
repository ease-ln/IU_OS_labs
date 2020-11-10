#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

int processNum = 0;
int resourcesNum = 0;
int checked = 0;
int locked = 0;

*E, *A, *check;
**current;
**request;

struct Process* processes;

void detection(char *inputName, char *outputName){
    checked = 0;
    //Initialization
    char buffer[BUFFER_SIZE];

    FILE *input = fopen(inputName, "r");
	FILE *output = fopen(outputName, "w+");

	fscanf(input, "%d", &processNum);
    fscanf(input, "%d", &resourcesNum);

	E = calloc(resourcesNum, sizeof(*E));
	A = calloc(resourcesNum, sizeof(*A));

	check = calloc(processNum, sizeof(*check));

	current = calloc(processNum, sizeof(*current));
	request = calloc(processNum, sizeof(*request));
	int *finished = calloc(processNum, sizeof(int));
	for (int i = 0; i < processNum; i++) {
		current[i] = calloc(resourcesNum, sizeof(*current[i]));
		request[i] = calloc(resourcesNum, sizeof(*request[i]));
		check[i] = 0;
	}

    //Reading
    for (int i = 0; i < resourcesNum; i++) {
		fscanf(input, "%d", &E[i]);
	}
	for (int i = 0; i < resourcesNum; i++) {
		fscanf(input, "%d", &A[i]);
	}
    for (int i = 0; i < processNum; i++) {
		for (int j = 0; j < resourcesNum; j++) {
			fscanf(input, "%d", &current[i][j]);
		}
	}
	for (int i = 0; i < processNum; i++) {
		for (int j = 0; j < resourcesNum; j++) {
			fscanf(input, "%d", &request[i][j]);
		}
	}

    int i = 0;
    while (i < processNum) {
        if(check[i] == 0) {
            int ch = 1;
            for(int j = 0; j < resourcesNum; j++){
                if(A[j] < request[i][j]){
                    ch = 0;
                }
            }
            if (ch) {
                for(int j = 0; j < resourcesNum; j++){
                A[j] += current[i][j];
                }
                check[i] = 1;
                checked++;
                i = -1;
            }
        }
        i++;
    }
    printf("Process %d is dedlocked\n", checked);

    int deadlock = 0;
	for (int i = 0; i < processNum; i++) {
		if (check[i] == 0) {
            deadlock = 1;
			fprintf(output, "Process %d is dedlocked\n", i);
		}
	}
	if(!deadlock) {
        fprintf(output, "All processes are done\n");
	}
    fclose(input);
	fclose(output);
}

int main(){

    detection("input_ok.txt", "output_ok.txt");
    detection("input_dl.txt", "output_dl.txt");

    return 0;
}

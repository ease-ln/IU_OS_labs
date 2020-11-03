#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    unsigned char append = 0;
    const char *fmode = "w";

    if(argc > 1) {
       if(strcmp(argv[1], "-a") == 0) {
            append = 1;
            fmode = "a";
        }
    }

    const int num_file = argc - 1 - append;
    FILE* files[num_file];

    for(int i = 0; i < num_file; i++) {
        files[i] = fopen(argv[1+append+i], fmode);
        if(files[i] == NULL) {
            exit(1);
        }
    }

    int ch;
    while((ch = getchar()) != -1) {
        putchar(ch);
        for(int i = 0; i < num_file; i++) {
            fputc(ch, files[i]);
        }
    }

    for(int i = 0; i < num_file; i++) {
        fclose(files[i]);
    }
    return (0);
}

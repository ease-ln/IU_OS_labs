#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
char* concat(const char *s1, const char *s2) {
    char *s3 = malloc(strlen(s1) + strlen(s2) + 1);
    strcpy(s3, s1);
    strcat(s3, s2);
    return s3;
}

#define N 100
int main()
{
  DIR *d = opendir("tmp");
    struct dirent *dir;
    FILE *ex4 = fopen("ex4.txt", "w");
    int i_nodes[N];
    int i_nodes_freq[N];
    char** filenames[N];
    int num = 0;

    if (d){
        //Lets initialize all arrays
        for(size_t i = 0; i < N; i++){
            i_nodes[i] = -1;
            i_nodes_freq[i] = 0;
            filenames[i] = (char**)malloc(sizeof(char*) * N);
        }

        while(dir = readdir(d)){
            if((!strcmp(dir->d_name, ".")) || (!strcmp(dir->d_name, "..")))
                continue;
            int num_of_dif_i_node = 0;
            struct stat file_stat;
            int ret = stat(concat("tmp/", dir->d_name), &file_stat);
            if (ret < 0) {
                fprintf(ex4, 'Error\n');
            }
            int i_node = file_stat.st_ino;
            for(size_t i = 0; i < num; i++) {
                if(i_node == i_nodes[i]) {
                    filenames[i][i_nodes_freq[i]] = (char*)malloc(sizeof(char) * N);
                    strcpy(filenames[i][i_nodes_freq[i]], dir->d_name);
                    i_nodes_freq[i]++;
                    num_of_dif_i_node = 1;
                    break;
                }
            }
            if(num_of_dif_i_node == 0) {
                i_nodes[num] = i_node;
                i_nodes_freq[num] = 1;
                filenames[num][0] = (char*)malloc(sizeof(char) * N);
                strcpy(filenames[num][0], dir->d_name);
                num++;
            }
        }

        for(size_t i = 0; i < num; i++) {
            if(i_nodes_freq[i]<2)
                continue;
            fprintf(ex4, "%d : %d\n", i_nodes_freq[i], i_nodes[i]);
            for (size_t j = 0; j < i_nodes_freq[i]; j++)
            {
                fprintf(ex4, "%s\n", filenames[i][j]);
            }
        }

    } else{
        fprintf(ex4, "Directory is not presented!");
        exit(0);
    }

    fclose(ex4);
    closedir(d);
  return 0;
}

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <stdio.h>
/*
 sys/resourse.h library contains "rusage" structure that has ru_maxrss
 which represent memory usage(maximum resident set size) and RUSAGE_SELF = const.
*/

int main(){
    int size = 10;
    struct rusage usage;
    for(size_t i = 0; i < 10; i++){
        memset(malloc(size * 1024 *1024), '0', size * 1024 * 1024);

        if(getrusage(RUSAGE_SELF, &usage) == 0){
            printf("used: %ld KB\n", usage.ru_maxrss);
        } else {
            printf("Error\n");
        }
        sleep(1);
    }
return 0;
}

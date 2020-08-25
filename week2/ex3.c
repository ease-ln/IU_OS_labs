#include <stdio.h>
#include <stdlib.h>

void triangle(int n);

int main(int argc, char *argv[]){
int n;
if (sscanf(argv[1],"%d", &n) != 1){
   printf("n can not be less than 2 \n");
   printf("argv = %d\n", n);
 return -1;
}
triangle(6);
return 0;
}
void triangle(int n){
    int c=n;
for(int i = 1; i<=n; i++){
    for(int k=1; k<=c; k++){
        printf(" ");
    }
     for(int j=1; j<=i*2-1; j++){
        printf("*");
     }
    c = c-1;
    printf("\n");
    }

}


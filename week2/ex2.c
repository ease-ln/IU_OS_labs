#include <stdio.h>
#include <string.h>

#define lens 1000

int main(){
    char s1[lens];
    puts("Enter to string");
    fgets(s1, lens, stdin);
    printf("Reverse string");
    for(int i=strlen(s1)-1; i>=0; i--){
        if(s1[i]!="/n"){
            putchar(s1[i]);
        }
    }
return 0;
}

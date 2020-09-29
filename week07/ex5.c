#include <stdio.h>
int main() {
char **s = malloc(1);
char foo[] = "Hello World";
//int size = sizeof(foo) / sizeof(foo[0]);
*s = foo;
printf("s is %s\n", *s);
s[0] = foo;
printf("s[0] is %s\n", s[0]);
return(0);
}

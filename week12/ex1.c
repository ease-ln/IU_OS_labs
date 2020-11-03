#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
   char command[200];

   strcpy( command, "head /dev/random | tr -dc A-Za-z0-9 | head -c 20 > ex1.txt");
   system(command);

   return(0);
}

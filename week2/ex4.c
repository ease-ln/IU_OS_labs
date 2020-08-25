#include <stdio.h>

void swap(int *x, int *y);

int main(){
    int x, y;
    printf("x ");
    scanf("%d", &x);
    printf("\ny ");
    scanf("%d", &y);
    swap(&x, &y);
    printf("\nSwap: x = %d, y = %d", x, y);
    return 0;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}


#include <stdio.h>

int main(){
  int n;
  printf("Enter the number of elemens:");
  scanf("%d", &n);
  int *arr = malloc(n *sizeof(int));

  for(int i = 0; i < n; i++){
    arr[i] = i;
  }

  for(int i = 0; i < n; i++){
    printf("%d ", arr[i]);
  }

  free(arr);
}

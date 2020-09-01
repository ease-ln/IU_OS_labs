#include <stdio.h>

void bubble_sort(int[], int);
int main(){
int arr[100], n;

printf("Enter number of elements\n");
scanf("%ld", &n);
printf("Enter %ld integers\n", n);
for (int c = 0; c < n; c++)
    scanf("%d", &arr[c]);

bubble_sort(arr, n);

printf("Sorted array:\n");
for (int i = 0; i < n; i++)
     printf("%d\n", arr[i]);

return 0;
}

void bubble_sort(int arr[], int n){
int temp;
for(int i = 0; i< n-1; i++){
    for(int j = 0; j<n-i-1; j++){
        if(arr[j]>arr[j+1]){
            temp = arr[j];
            arr[j]= arr[j+1];
            arr[j+1]= temp;
        }
    }
}
}

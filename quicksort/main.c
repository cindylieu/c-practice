#include <stdio.h>
#include "sort.h"

int main() {
    int i = 0;
    int size = 0;

    printf ("Please enter the size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("\n");

    printf ("Please enter %d whole numbers into the array\n", size);
    for (i = 0; i < size; i++){
        scanf(" %d", &arr[i]);
    }

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("**********\n");

    quicksort(&arr, 0, size-1);

    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("**********\n");

}
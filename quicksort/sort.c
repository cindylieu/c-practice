//
// Created by Cindy Lieu on 10/17/19.
//

/*
 * (a) sort.c will contain the main program, which essentially reads in the input, calls
   quicksort and prints the sorted output. The user is asked how many elements he wishes to
   sort. An array of the corresponding size is created dynamically. Then he is asked to enter
   the elements manually, as a sequence of numbers (in real life this sequence would be in
   a file.  File I/O is one of the very important things that we unfortunately won't have time
   to cover).
 */

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void swap (int* i, int* j){

    int temp;
    temp = *i;
    *i = *j;
    *j = temp;

}

int randomPivot (*arr, start, end){

    int pivot = rand() % (end-start) + start;
    swap (&arr[pivot], &arr[end]);
    return partition(arr, start, end);

}

int partition (*arr, start, end){

    int pivot = arr[end];
    int pIndex = start;
    int i;
    for (i = start; i < end; i++){
        if (arr[i] <= pivot) {
            swap (&arr[i],&arr[pIndex]);
            pIndex++;
        }
    }
    swap (&arr[pIndex], &arr[end]);
    return pIndex;

}

void quicksort (*arr, start, end){

    if (start < end){ //base statement
        int pIndex = randomPivot (arr, start, end);
        quicksort (arr, start, pIndex-1);
        quicksort (arr, pIndex+1, end);
    }

}
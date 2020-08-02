//
// Created by Cindy Lieu on 10/23/19.
//
#ifndef HW4_Quicksort_SORT_H
#define HW4_Quicksort_SORT_H

void readInput();
void swap (int* i, int* j);
void quicksort (int* arr, int start, int end);
int partition (*arr, int start, int end);
int randomPivot (int* arr, int start, int end);

#endif //W4_Quicksort_SORT_H

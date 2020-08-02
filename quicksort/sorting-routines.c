//
// Created by Cindy Lieu on 10/17/19.
//

/*
 * (b) sorting-routines.c will contain quicksort, insertionsort, along with their auxiliary
   functions (e.g. partition, get-pivot, etc. Feel free to use any names you like).
   Quicksort should look like this:
             procedure quicksort(array segment)
             1. If size of array segment is less than 8 call insertionsort
             2. Otherwise:
                   a. pick a random element x from the segment
                   b. partition the array around x.
                   c. recursively quicksort the two segments the partition produces.
 */

#include <stdio.h>
#include <stdlib.h>
#include "sort.h"


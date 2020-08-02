#include <stdio.h>

int main() {

    /* FIRST REFINEMENT */

    /*
    printf("%4s\n", "x");
    printf("%3s%2s\n", "x", "x");
    printf("%2s%2s%2s\n", "x", "x", "x");
    printf("%3s%2s\n", "x", "x");
    printf("%4s\n", "x");
    */

    /* SECOND REFINEMENT */

    /*
    char c;
    int size;

    printf("Please enter a letter \n");
    c = getchar();

    printf("Please enter a size \n");
    scanf("%d", &size);

    int starter = 0;
    int iteration = size/2;
    int space = iteration;

    for (int i = 0; i < iteration; i++) {
        starter++;
        space--;
        for (int i = 0; i < space+1; i++) {
            printf(" ");
        }
        for (int i = 0; i < starter; i++) {
            printf("%2c", c);
        }
        printf("\n");
    }

    for(int i = 0; i <= iteration; i++){
        printf("%2c", c);
    }

    printf("\n");

    for (int i = 0; i < iteration+1; i++) {
        for (int i = 0; i < space+1; i++) {
            printf(" ");
        }
        for (int i = 0; i < starter; i++) {
            printf("%2c", c);
        }
        starter--;
        space++;
        printf("\n");
    } */

    /* THIRD REFINEMENT */

    char c;
    int size;

    printf("Please enter a letter \n");
    c = getchar();

    printf("Please enter a size \n");
    do {
        scanf("%d", &size);
        if (size%2 == 0 || size < 0){
            printf("ERROR: please only enter an odd, positive integer\n");
            printf("Enter a new size\n");}
    } while (size%2 == 0 || size < 0);

    int iteration = size/2;
    int space = iteration;

    for(int t = 0; t < iteration; t++){
        for (int i = 0; i < space; i++){
            printf(" ");
        }
        for (int i = 0; i <= t; i++){
            printf("%c ", c);
        }
        space--;
        printf("\n");
    }

    for(int m = 0; m <= iteration; m++){
        printf("%c ", c);
    }

    printf("\n");

    for(int b = 1; b < iteration+1; b++){
        for (int i = 0; i < b; i++){
            printf(" ");
        }
        for (int i = iteration; i >= b; i--){
            printf("%c ", c);
        }
        space--;
        printf("\n");
    }
}
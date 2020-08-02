#include <stdio.h>

int main() {
    //Full outer bound

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
    int space = iteration+1;
    int hold = 0;

    for(int t = 1; t < iteration+1; t++){
        for (int i = 0; i < space; i++){
            printf("%c", c);
        }
        for (int i = 0; i < (t+hold); i++){
            printf(" ");
        }
        hold = t;
        for (int i = 0; i < space; i++){
            printf("%c", c);
        }
        space--;
        printf("\n");
    }

    for(int m = 0; m < 1; m++){
        printf("%c", c);
    }
    for(int m = 0; m < size; m++){
        printf(" ");
    }
    for(int m = 0; m < 1; m++){
        printf("%c", c);
    }

    printf("\n");

    hold = size;

    for(int b = 2; b < iteration+2; b++){
        for(int i = 0; i < b; i++){
            printf("%c", c);
        }
        for(int i = 0; i < hold-2; i++){
            printf(" ");
        }
        for(int i = 0; i < b; i++){
            printf("%c", c);
        }
        hold = hold - 2;
        printf("\n");
    }


    //Diamond border
    /*
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
    int space = iteration+1;
    int hold = 0;

    for(int t = 1; t < iteration+1; t++){
        for (int i = 0; i < space-1; i++){
            printf(" ");
        }
        printf("%c", c);
        for (int i = 0; i < (t+hold); i++){
            printf(" ");
        }
        hold = t;
        printf("%c", c);
        for (int i = 0; i < space-1; i++){
            printf(" ");
        }
        space--;
        printf("\n");
    }

    for(int m = 0; m < 1; m++){
        printf("%c", c);
    }
    for(int m = 0; m < size; m++){
        printf(" ");
    }
    for(int m = 0; m < 1; m++){
        printf("%c", c);
    }

    printf("\n");

    hold = size;

    for(int b = 2; b < iteration+2; b++){
        for(int i = 0; i < b-1; i++){
            printf(" ");
        }
        printf("%c", c);
        for(int i = 0; i < hold-2; i++){
            printf(" ");
        }
        printf("%c", c);
        for(int i = 0; i < b-1; i++){
            printf(" ");
        }
        hold = hold - 2;
        printf("\n");
    }
    */


    //Perfect diamond boarder

//    char c;
//    int size;
//
//    printf("Please enter a letter \n");
//    c = getchar();
//
//    printf("Please enter a size \n");
//    do {
//        scanf("%d", &size);
//        if (size%2 == 0 || size < 0){
//            printf("ERROR: please only enter an odd, positive integer\n");
//            printf("Enter a new size\n");}
//    } while (size%2 == 0 || size < 0);
//
//    int iteration = size/2;
//    int space = iteration+1;
//    int hold = 0;
//
//    for (int i = 0; i < space-1; i++){
//        printf(" ");
//    }
//    printf("%c\n", c);
//
//    for(int t = 1; t < iteration; t++){
//        for (int i = 0; i < space-2; i++){
//            printf(" ");
//        }
//        printf("%c", c);
//        for (int i = 0; i < (t+hold); i++){
//            printf(" ");
//        }
//        hold = t;
//        printf("%c", c);
//        for (int i = 0; i < space-1; i++){
//            printf(" ");
//        }
//        space--;
//        printf("\n");
//    }
//
//    for(int m = 0; m < 1; m++){
//        printf("%c", c);
//    }
//    for(int m = 0; m < size-2; m++){
//        printf(" ");
//    }
//    for(int m = 0; m < 1; m++){
//        printf("%c", c);
//    }
//
//    printf("\n");
//
//    hold = size-2;
//
//    for(int b = 2; b < iteration+1; b++){
//        for(int i = 0; i < b-1; i++){
//            printf(" ");
//        }
//        printf("%c", c);
//        for(int i = 0; i < hold-2; i++){
//            printf(" ");
//        }
//        printf("%c", c);
//        for(int i = 0; i < b-1; i++){
//            printf(" ");
//        }
//        hold = hold - 2;
//        printf("\n");
//    }
//
//    space = iteration+1;
//
//    for (int i = 0; i < space-1; i++){
//        printf(" ");
//    }
//    printf("%c\n", c);
//
}
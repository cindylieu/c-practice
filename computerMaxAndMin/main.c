#include <stdio.h>

int main() {
    int x, max, min;

    printf("next number please? ");
    scanf(" %d", &x);
    max = x;
    min = x;

    if (x == -1){
        printf("Huh? no numbers? Next time, give me something useful.");
    } else
        while(x != -1){
            printf("next number please? ");
            scanf(" %d", &x);
            if (x == -1){
                break;
            }

            if(x > max){
                max = x;
            }
            if(x < min){
                min = x;
            }
        }
        printf("The maximum is %d and the minimum is %d", max, min);

}
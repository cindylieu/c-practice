#include <stdio.h>

int n, pegs, moves, replay = 0;
char from_peg, to_peg, aux_peg1, aux_peg2, aux_peg3;

void towersOfHanoi3 (int n, char from_peg, char to_peg, char aux_peg1);
void towersOfHanoi4 (int n, char from_peg, char to_peg, char aux_peg1, char aux_peg2);
void towersOfHanoi5 (int n, char from_peg, char to_peg, char aux_peg1, char aux_peg2, char aux_peg3);

int main() {

    while (replay != 1){
        printf("Please enter number of pegs (3, 4, or 5): ");
        scanf("%d", &pegs);
        printf("Please enter number of disks: ");
        scanf("%d", &n);

        if (pegs == 3){
            towersOfHanoi3 (n, 'A', 'C', 'B');
            replay = 1;
        } else if (pegs == 4){
            towersOfHanoi4 (n, 'A', 'D', 'B', 'C');
            replay = 1;
        } else if (pegs == 5){
            towersOfHanoi5(n, 'A', 'E', 'B', 'C', 'D');
            replay = 1;
        } else {
            printf("Please enter either 3, 4, or 5 pegs.\n");
        }
    }

    return 0;
}

void towersOfHanoi3(int num, char from_peg, char to_peg, char aux_peg1)
    {
        if (num == 1) {
            printf("\n Move disk 1 from peg %c to peg %c", from_peg, to_peg);
            return;
        }

        towersOfHanoi3(num - 1, from_peg, aux_peg1, to_peg);
        printf("\n Move disk %d from peg %c to peg %c", num, from_peg, to_peg);
        towersOfHanoi3(num - 1, aux_peg1, to_peg, from_peg);
    }

void towersOfHanoi4(int n, char from_peg, char to_peg, char aux_peg1, char aux_peg2) {
    if (n == 0)
        return;
    if (n == 1) {
        printf("\n Move disk %d from rod %c to rod %c", n, from_peg, to_peg);
        return;
    }

    towersOfHanoi4(n - 2, from_peg, aux_peg1, aux_peg2, to_peg);
    printf("\n Move disk %d from rod %c to rod %c ", n - 1, from_peg, aux_peg2);
    printf("\n Move disk %d from rod %c to rod %c ", n, from_peg, to_peg);
    printf("\n Move disk %d from rod %c to rod %c ", n - 1, aux_peg2, to_peg);
    towersOfHanoi4(n - 2, aux_peg1, to_peg, from_peg, aux_peg2);
    }

void towersOfHanoi5 (int n, char from_peg, char to_peg, char aux_peg1, char aux_peg2, char aaux_peg3) {
    if (n == 0)
        return;
    if (n == 1) {
        printf("\n Move disk %d from rod %c to rod %c", n, from_peg, to_peg);
        return;
    }

    towersOfHanoi5(n - 2, from_peg, aux_peg1, aux_peg2, aaux_peg3, to_peg);
    printf("\n Move disk %d from rod %c to rod %c ", n - 1, from_peg, aux_peg2);
    printf("\n Move disk %d from rod %c to rod %c ", n, from_peg, to_peg);
    printf("\n Move disk %d from rod %c to rod %c ", n - 1, aux_peg2, to_peg);
    towersOfHanoi5(n - 2, aux_peg1, to_peg, from_peg, aux_peg2, aaux_peg3);
}
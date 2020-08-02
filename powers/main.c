#include <stdio.h>

long int base, num, n;
int count, badCount;

long power (long int, long int);
long powerBad (long int, long int);

int main(void) {

    count = 0;
    badCount = 0;
    printf("PLease enter a base number: ");
    scanf("%d", &num);

    printf("Please enter a power: ");
    scanf("%d", &n);

    printf("%ld\n", power(num, n));
    printf("%ld\n", powerBad(num, n));

    printf("Counts: %d %d\n", count, badCount);
    return 0;
};

long power (long int num, long int n){
    base = num;
    count++;
    if(n == 2){
        return num *= num;
    } else if (n%2 != 0){
        n--;
        return num = power(num, n) * base;
    } else{
        n /=2;
        return num = power(num, n) * power(num, n);
    }
}

long powerBad(long x, long n)
{
    badCount++;
    if(n == 0) return 1;
    else return x * powerBad(x, n-1);
}
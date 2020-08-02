#include <stdio.h>

// LEAP YEAR TEST
int leapYearTest(int year){
    if (year%400 == 0){
        return 1;
    } else if (year%100 == 0){
        return 0;
    } else if (year%4 == 0){
        return 1;
    } else {
        return 0;
    }
}

//  DAY OF MONTH
int dayOfMonth(int day, int month, int year){
    //calendar arrays
    int monthKey[] = {1, 4, 4, 0, 2, 5, 0, 3, 6, 1, 4, 6};
    int centuryCode[] = {4, 2, 0, 6};
    int week[] = {1, 2, 3, 4, 5, 6, 7};
    int test;

    //calculations
    int lastTwo = year % 100;
    test = lastTwo/4;
    test += day;
    test += monthKey[month-1];

    if((leapYearTest(year) == 1 && month == 1) || (leapYearTest(year) == 1 && month == 2)){
        test -= 1;
    }

    if (year/100 == 17){
        test += centuryCode[0];
    } else if (year/100 == 18){
        test += centuryCode[1];
    } else if (year/100 == 19){
        test += centuryCode[2];
    } else if (year/100 == 20){
        test += centuryCode[3];
    } else {
        test += centuryCode[3];
    }

    test += lastTwo;
    test = test%7;

    if(test == 0){
        test = 1;
    }

    return test;
}

// PRINTING CALENDAR
int pMonth(int month, int year){

    int dayStart = dayOfMonth(1, month, year);
    int skipDay;
    int day = 1;
    int monthLen;

    char * monthArr[] = {"January", "February", "March", "April", "May", "June", "July", "August",
                         "September", "October", "November", "December"};

    if (dayStart == 1){
        skipDay = 0;
    } else {
        skipDay = 1;
    }

    printf("    %s %d\n", monthArr[month-1], year);
    printf(" Su Mo Tu We Th Fr Sa\n");

    if(month == 2 && leapYearTest(year) == 1){
        monthLen = 29;
    } else if (month == 2){
        monthLen = 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11){
        monthLen = 30;
    } else {
        monthLen = 31;
    }

    // int, month. year
    while (day <= monthLen) {
        for (int weekDay = 1; weekDay <= 7; weekDay++) {
            if (skipDay == 1) {
                for (int space = 1; space < dayStart * 3 - 2; space++) {
                    printf(" ");
                }
                skipDay = 0;
                weekDay = dayStart;
            }
            if (day < 10) {
                printf(" ");
                printf(" %d", day);
            } else if (day > 9 && day <= monthLen) {
                printf(" ");
                printf("%d", day);
            }
            day++;
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}

int pQuarter (int year, int quarter){
    if (quarter == 1){
        for (int i = 1; i <= 3; i++ ){
            pMonth( i, year);
        }
    } else if (quarter == 2){
        for (int i = 4; i <= 6; i++ ){
            pMonth( i, year);
        }
    } else if (quarter == 3){
        for (int i = 7; i <= 9; i++ ){
            pMonth( i, year);
        }
    } else if (quarter == 4){
        for (int i = 10; i <= 12; i++ ){
            pMonth( i, year);
        }
    }
}

//main
int main() {

    int choice, month, year, quarter;
    int play = 1;

    while (play == 1){
        printf("\n");
        printf("***Welcome to Newt's Calendar Program***\n\n");
        printf("You have the following choices:\n"
               "1. Leap year test\n"
               "2. Get the first day of the month\n"
               "3. Get a monthly calendar\n"
               "4. Get a quarterly calendar\n"
               "5. Quit\n"
               "\n"
               "Please enter your choice from the above menu: ");
        scanf("%d", &choice);

        if (choice == 1){ //Leap year test

            printf("Please enter the year to test: ");
            scanf("%d", &year);

            if (leapYearTest(year)==1){
                printf("%d is a leap year.", year);
            } else {
                printf("%d is not a leap year.", year);
            }

            printf("\n");

        } else if (choice == 2){ //First day of month

            char * week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

            printf("Please enter the year: ");
            scanf("%d", &year);
            printf("Please enter the month: ");
            scanf("%d", &month);
            int d = dayOfMonth(1, month, year);

            printf("%s", week[d-1]);

            printf("\n");
        } else if (choice == 3){ // Prints one month

            printf("Please enter the year: ");
            scanf("%d", &year);
            printf("Please enter the month you wish to print: ");
            scanf("%d", &month);
            printf("\n");
            pMonth(month, year);

        } else if (choice == 4){ //prints quarter

            printf("Please enter the year: ");
            scanf("%d", &year);
            printf("Please enter the quarter (either 1, 2, 3, or 4): ");
            scanf("%d", &quarter);
            pQuarter(year, quarter);

            printf("\n");
        } else if (choice == 5){ // quits

            play = 0;

        } else {

            printf("This is not a valid choice.");
            printf("\n");

        }

    }
}
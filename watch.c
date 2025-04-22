#include <time.h>

#include "watch.h"

char zero[] = 
"  0000000000000  \033[B\033[17D"
"  00         00  \033[B\033[17D"
"  00         00  \033[B\033[17D"
"  00         00  \033[B\033[17D"
"  00         00  \033[B\033[17D"
"  00         00  \033[B\033[17D"
"  00         00  \033[B\033[17D"
"  00         00  \033[B\033[17D"
"  0000000000000  ";

char one[] = 
"             11  \033[B\033[17D"
"             11  \033[B\033[17D"
"             11  \033[B\033[17D"
"             11  \033[B\033[17D"
"             11  \033[B\033[17D"
"             11  \033[B\033[17D"
"             11  \033[B\033[17D"
"             11  \033[B\033[17D"
"             11  ";

char two[] = 
"  2222222222222  \033[B\033[17D"
"             22  \033[B\033[17D"
"             22  \033[B\033[17D"
"             22  \033[B\033[17D"
"  2222222222222  \033[B\033[17D"
"  22             \033[B\033[17D"
"  22             \033[B\033[17D"
"  22             \033[B\033[17D"
"  2222222222222  ";

char three[] = 
"  3333333333333  \033[B\033[17D"
"             33  \033[B\033[17D"
"             33  \033[B\033[17D"
"             33  \033[B\033[17D"
"  3333333333333  \033[B\033[17D"
"             33  \033[B\033[17D"
"             33  \033[B\033[17D"
"             33  \033[B\033[17D"
"  3333333333333  ";

char four[] = 
"  44         44  \033[B\033[17D"
"  44         44  \033[B\033[17D"
"  44         44  \033[B\033[17D"
"  44         44  \033[B\033[17D"
"  4444444444444  \033[B\033[17D"
"             44  \033[B\033[17D"
"             44  \033[B\033[17D"
"             44  \033[B\033[17D"
"             44  ";

char five[] = 
"  5555555555555  \033[B\033[17D"
"  55             \033[B\033[17D"
"  55             \033[B\033[17D"
"  55             \033[B\033[17D"
"  5555555555555  \033[B\033[17D"
"             55  \033[B\033[17D"
"             55  \033[B\033[17D"
"             55  \033[B\033[17D"
"  5555555555555  ";

char six[] = 
"  6666666666666  \033[B\033[17D"
"  66             \033[B\033[17D"
"  66             \033[B\033[17D"
"  66             \033[B\033[17D"
"  6666666666666  \033[B\033[17D"
"  66         66  \033[B\033[17D"
"  66         66  \033[B\033[17D"
"  66         66  \033[B\033[17D"
"  6666666666666  ";

char seven[] = 
"  7777777777777  \033[B\033[17D"
"             77  \033[B\033[17D"
"             77  \033[B\033[17D"
"             77  \033[B\033[17D"
"             77  \033[B\033[17D"
"             77  \033[B\033[17D"
"             77  \033[B\033[17D"
"             77  \033[B\033[17D"
"             77  ";

char eight[] = 
"  8888888888888  \033[B\033[17D"
"  88         88  \033[B\033[17D"
"  88         88  \033[B\033[17D"
"  88         88  \033[B\033[17D"
"  8888888888888  \033[B\033[17D"
"  88         88  \033[B\033[17D"
"  88         88  \033[B\033[17D"
"  88         88  \033[B\033[17D"
"  8888888888888  ";

char nine[] = 
"  9999999999999  \033[B\033[17D"
"  99         99  \033[B\033[17D"
"  99         99  \033[B\033[17D"
"  99         99  \033[B\033[17D"
"  9999999999999  \033[B\033[17D"
"             99  \033[B\033[17D"
"             99  \033[B\033[17D"
"             99  \033[B\033[17D"
"  9999999999999  ";

char *number[] = {zero, one, two, three, four, five, six, seven, eight, nine};

void init_watch(Watch *watch)
{
    char dot[] = "     \033[B\033[5D     \033[B\033[5D     \033[B\033[5D     \033[B\033[5D     \033[B\033[5D     \033[B\033[5D     \033[B\033[5D DDD \033[B\033[5D DDD ";

    char colon[] = "     \033[B\033[5D CCC \033[B\033[5D CCC \033[B\033[5D     \033[B\033[5D     \033[B\033[5D     \033[B\033[5D CCC \033[B\033[5D CCC \033[B\033[5D     ";
    
    printf("\033[2J\033[1;1H");
    
    printf("%s", number[(watch->hour / 10) % 10]);
    printf("\033[8A");
    printf("%s", number[watch->hour % 10]);
    printf("\033[8A");
    printf("%s", colon);

    printf("\033[8A");
    printf("%s", number[(watch->min / 10) % 6]);
    printf("\033[8A");
    printf("%s", number[watch->min % 10]);
    printf("\033[8A");
    printf("%s", dot);

    printf("\033[8A");
    printf("%s", number[(watch->sec / 10) % 6]);
    printf("\033[8A");
    printf("%s", number[watch->sec % 10]);
}

void set_counter(int time)
{
    if (time % 10 == 0) {
        printf("\033[8A");
        printf("%s", number[(time / 10) % 10]);
    }
    printf("\033[8A");
    printf("%s", number[time % 10]);
}

void get_time(Watch *watch)
{
    time_t t;
    time(&t);
    struct tm *ltm;
    ltm = localtime(&t);

    watch->hour = ltm->tm_hour;
    watch->min = ltm->tm_min;
    watch->sec = ltm->tm_sec;
}

int get_countup(Watch *watch)
{
    int n_countup = 0;
    if (watch->sec == 0) {
        n_countup++;

        if (watch->min == 0) {
            n_countup++;
        }
    }

    return n_countup;
}

void set_watch(Watch *watch, int  countup)
{
    if(countup == 0) {
        if (watch->sec % 10 != 0) printf("\033[17D");
        else printf("\033[34D");
    }
    else if (countup == 1) {
        if ((watch->min % 10) != 0) printf("\033[56D");
        else printf("\033[73D");
    }
    else if (countup == 2) {
        if ((watch->hour % 10) != 0) printf("\033[95D");
        else printf("\033[112D");
    }

    switch (countup) {
        case 2:
            set_counter(watch->hour);
            printf("\033[5C");
        case 1:
            set_counter(watch->min);
            printf("\033[5C");
        case 0:
            set_counter(watch->sec);
    }  
}

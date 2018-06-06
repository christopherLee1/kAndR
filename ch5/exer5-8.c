#include <stdio.h>

// month_day(1988, 60, &m, &d)
// sets m to 2 and d to 29 for Feb 29

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    if (month > 12 || day > 32)
        return -1;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (day > daytab[leap][month])
        return -1;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if ((leap && yearday > 366) || (!leap && yearday > 365)) {
        *pmonth = -1;
        *pday = -1;
    } else {
        for (i = 1; yearday > daytab[leap][i]; i++)
            yearday -= daytab[leap][i];
        *pmonth = i;
        *pday = yearday;
    }
}

int main()
{
    int month, day, day_year;
    int m = 3, d = 30, y = 1988;
    day_year = day_of_year(y, m, d);
    char leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    if (day_year == -1) {
        printf("error: day %d is not in valid range (1-%d) for month %d\n", d, daytab[leap][m], m);
        return -1;
    }
    printf("%d\n", day_of_year(y, m, d));
    month_day(1988, 367, &month, &day);
    if (month < 1 || day < 1) {
        printf("invalid yearday number: %d\n", 367);
        return -1;
    }
    printf("%d %d\n", month, day);
    return 0;
}

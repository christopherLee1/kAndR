#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearchV2(int x, int v[], int n);

#define MAXSIZE 100000

/* binary search standard version */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1; /* no match */
}
/* binary search with one test in loop */
int binsearchV2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return x == v[low] ? low : -1; /* no match */
}

int main()
{
    // timing code stolen from: https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
    int v[MAXSIZE];
    int i, x, y;
    clock_t start, end;
    for (i = 0; i < MAXSIZE; i++)
        v[i] = i;
    start = clock();
    x = binsearch(1234,v,MAXSIZE);
    end = clock() - start;
    printf("binsearch(1234,v,100) = %d took %fs\n", x, (double)end/CLOCKS_PER_SEC);
    start = clock();
    y = binsearch(1234,v,MAXSIZE);
    end = clock() - start;
    printf("binsearch(1234,v,100) = %d took %fs\n", y, (double)end/CLOCKS_PER_SEC);
}

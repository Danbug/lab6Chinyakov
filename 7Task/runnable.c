#include <stdio.h>
#include <stdlib.h>

//
int main(int argc, char *argv[])
{
    int totalSum = 0;
    if (argc == 1)
    {
        printf("Args error\n");
        return 0;
    }

    int n = atoi(argv[1]);

    // initialize first and second terms
    int t1 = 0, t2 = 1;

    // initialize the next term (3rd term)
    int nextTerm = t1 + t2;

    // print the first two terms t1 and t2
    printf("Fibonacci Series: %d, %d, ", t1, t2);

    totalSum+= t1;
    totalSum+= t2;

    // print 3rd to nth terms
    for (int i = 3; i <= n; ++i)
    {
        totalSum+= nextTerm;
        printf("%d, ", nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }

    return totalSum;
}
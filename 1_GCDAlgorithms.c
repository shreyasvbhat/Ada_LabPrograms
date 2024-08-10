#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int count = 0;

int euclid(int m, int n)
{
    count = 0;
    while (n != 0)
    {
        int temp = m % n;
        m = n;
        n = temp;
        count++;
    }

    return m;
}

int consecutiveIntegerCheck(int m, int n)
{
    count = 0;
    int t = m > n ? n : m;
    for (int i = t; i > 0; i--)
    {
        count++;
        if (m % i == 0)
        {
            count++;
            if (n % i == 0)
                return i;
        }
    }

    return m > n ? m : n;
}

int modifiedEuclids(int m, int n)
{
    count = 0;

    while (n != 0)
    {
        count++;
        if (m < n)
        {
            int temp = m;
            m = n;
            n = temp;
        }

        m -= n;
    }

    return m;
}

void tester()
{
    int m, n;
    printf("Enter 2 numbers : ");
    scanf("%d%d", &m, &n);

    if (m < 0 && n < 0)
    {
        printf("Cannot find gcd...Invalid inputs...");
    }

    printf("gcd through euclid algorithm :%d\n", euclid(m, n));
    printf("gcd through consecutive checking method :%d\n", consecutiveIntegerCheck(m, n));
    printf("gcd through repeated subtraction method :%d\n", modifiedEuclids(m, n));
}

int *execute(int (*func)(int, int), int i)
{
    int *arr = (int *)malloc(2 * sizeof(int));
    arr[0] = INT_MAX;
    arr[1] = INT_MIN;

    for (int j = 2; j <= i; j++)
    {
        for (int k = 2; k <= i; k++)
        {
            func(j, k);
            if (count < arr[0])
                arr[0] = count;
            if (count > arr[1])
                arr[1] = count;
        }
    }
    return arr;
}

void plotter()
{
    FILE *f1 = fopen("euclidBest.txt", "w");
    FILE *f2 = fopen("euclidWorst.txt", "w");
    FILE *f3 = fopen("consecBest.txt", "w");
    FILE *f4 = fopen("consecWorst.txt", "w");
    FILE *f5 = fopen("modifiedBest.txt", "w");
    FILE *f6 = fopen("modifiedWorst.txt", "w");

    for (int i = 10; i <= 100; i += 10)
    {
        int *arr = execute(euclid, i);
        fprintf(f1, "%d\t%d\n", i, arr[0]);
        fprintf(f2, "%d\t%d\n", i, arr[1]);

        arr = execute(consecutiveIntegerCheck, i);
        fprintf(f3, "%d\t%d\n", i, arr[0]);
        fprintf(f4, "%d\t%d\n", i, arr[1]);

        arr = execute(modifiedEuclids, i);
        fprintf(f5, "%d\t%d\n", i, arr[0]);
        fprintf(f6, "%d\t%d\n", i, arr[1]);
    }
}

void main()
{
    int ch;
    printf("\nEnter:\n1.Tester\n2.Plotter\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        tester();
        break;
    case 2:
        plotter();
        break;
    default:
        printf("Invalid Choice!!");
    }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int count;

int binarySearch(int key, int *a, int high, int low)
{
    count++;
    int mid = (high + low) / 2;
    if (low > high)
        return -1;
    if (*(a + mid) == key)
        return mid;
    else if (*(a + mid) > key)
        return binarySearch(key, a, mid - 1, low);
    else
        return binarySearch(key, a, high, mid + 1);
}

void tester()
{
    int *arr, n, key, ch, ans;
    printf("\nEnter array size: ");
    scanf("%d", &n);
    arr = (int *)malloc(n * sizeof(int));
    printf("\nEnter array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
    printf("\nEnter key to be searched : ");
    scanf("%d", &key);
    ans = binarySearch(key, arr, n - 1, 0);
    if (ans == -1)
        printf("\nKey not found!\n");
    else
        printf("\nKey found at %d index\n", ans);
}

void plotter()
{
    srand(time(NULL));
    int *arr;
    int n, key, r;
    FILE *f1, *f2, *f3;
    f1 = fopen("binarybest.txt", "w");
    f2 = fopen("binaryavg.txt", "w");
    f3 = fopen("binaryworst.txt", "w");
    n = 2;
    while (n <= 1024)
    {
        arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++)
            *(arr + i) = 1;
        int mid = (n - 1) / 2;
        *(arr + mid) = 0;
        count = 0;
        r = binarySearch(0, arr, n - 1, 0);
        fprintf(f1, "%d\t%d\n", n, count);
        for (int i = 0; i < n; i++)
            *(arr + i) = i+1;
        key = rand() % n + 1;
        count = 0;
        r = binarySearch(key, arr, n - 1, 0);
        fprintf(f2, "%d\t%d\n", n, count);
        for (int i = 0; i < n; i++)
            *(arr + i) = 0;
        count = 0;
        r = binarySearch(1, arr, n - 1, 0);
        fprintf(f3, "%d\t%d\n", n,count);
        n = n * 2;
        free(arr);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

void main()
{
    int ch;
    printf("Enter your choice:\n\n1.Tester\n2.Plotter\n");
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
        printf("Invalid choice!!!\n");
    }
}
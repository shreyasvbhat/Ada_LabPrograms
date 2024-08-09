#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

int n, opcount, dist[100][100];

int floyds(int adjMat[n][n], int n)
{
    opcount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adjMat[i][j] == -1)
                dist[i][j] = INT_MAX;
            else
                dist[i][j] = adjMat[i][j];
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
        {
            int tempDist = dist[i][k];
            for (int j = 0; j < n; j++)
            {
                if (dist[i][j] > tempDist)
                {
                    opcount++;
                    if (dist[k][j] != INT_MAX && dist[i][j] > tempDist + dist[k][j])
                    {
                        dist[i][j] = tempDist + dist[k][j];
                    }
                }
            }
        }
}

void tester()
{
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    int adjMat[n][n];
    printf("Enter adjacency matrix: \n");
    printf("[Note: Enter -1 to indicate infinity]\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMat[i][j]);
    floyds(adjMat, n);
    printf("Shortest distance between all pair of nodes:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d\t", dist[i][j]);
        printf("\n");
    }
}

void plotter()
{
    srand(time(NULL));
    FILE *fp = fopen("floydes.txt", "w");
    for (int k = 2; k < 12; k++)
    {
        n = k;
        int adjMat[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    adjMat[i][j] = rand();
                else
                    adjMat[i][j] = 0;
        floyds(adjMat, n);
        fprintf(fp, "%d\t%d\n", n, opcount);
    }
    fclose(fp);
}

void main()
{
    int ch;
    printf("Enter\n1.Tester\n2.Plotter\n");
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
        printf("Invalid choice!! ");
    }
}
#include <stdio.h>
#include <stdlib.h>

int isCycle = 0, components = 0, n, opcount = 0, isTester = 0;

void dfs(int mat[n][n], int *vis, int source, int par)
{
    vis[source] = 1;

    if (isTester)
        printf("%d ", source);

    for (int i = 0; i < n; i++)
    {
        opcount++;
        if (mat[source][i] && vis[i] && i != par)
            isCycle = 1;
        else if (mat[source][i] && !vis[i])
            dfs(mat, vis, i, source);
    }
}

void checkConnectivity(int mat[n][n])
{
    int vis[n], k = 1;

    for (int i = 0; i < n; i++)
        vis[i] = 0;

    for (int i = 0; i < n; i++)
        if (!vis[i])
        {
            components++;

            if (isTester)
                printf("\nComponent %d: ", k++);
            dfs(mat, &vis[0], i, -1);
        }
}

void tester()
{
    isTester = 1;
    printf("Enter the number of vertices\n");
    scanf("%d", &n);
    int adjMat[n][n];
    printf("Enter the adjacency matrix :\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMat[i][j]);

    checkConnectivity(adjMat);

    printf("\nThe number of connected components :%d\n", components);

    if (isCycle)
        printf("Cycle exists\n");
    else
        printf("Cycle doesnot exists\n");
}

void plotter()
{
    FILE *f1 = fopen("dfsadjMat.txt", "w");
    isTester = 0;

    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int adjMat[n][n];

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j)
                    adjMat[i][j] = 1;
                else
                    adjMat[i][j] = 0;
            }
        }
        opcount = 0;
        checkConnectivity(adjMat);
        fprintf(f1, "%d\t%d\n", n, opcount);
    }
    fclose(f1);
}

void main()
{
    int choice;
    printf("Enter\n1.Tester\n2.Plotter\n");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        tester();
        break;
    case 2:
        plotter();
        break;
    default:
        printf("Invalid choice");
    }
}
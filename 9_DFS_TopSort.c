#include <stdio.h>
#include <stdlib.h>

int n, opcount = 0, top = -1, ans[100];

int dfs(int mat[n][n], int *vis, int *stack, int s, int *ans)
{
    vis[s] = 1, stack[s] = 1;
    for (int i = 0; i < n; i++)
    {
        opcount++;
        if (mat[s][i] && stack[i] && vis[i])
            return 0;
        if (mat[s][i] && !vis[i] && dfs(mat, vis, stack, i, ans))
            return 0;
    }
    ans[++top] = s;
    stack[s] = 0;
    return 1;
}

int check(int mat[n][n])
{
    int vis[n], stack[n];
    ans[n];
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfs(mat, &vis[0], &stack[0], i, &ans[0]))
                return 1;
        }
    }
    return 0;
}

void tester()
{
    printf("Enter number of vertices:\n");
    scanf("%d", &n);
    int adjMat[n][n];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adjMat[i][j]);
    if (check(adjMat))
    {
        printf("Cycle exists..Cannot perform topological sorting!!!\n");
        exit(0);
    }
    else
    {
        printf("Topological sorting order:\n");
        while (top != -1)
            printf("%d ", ans[top--]);
        printf("\n");
    }
}

void plotter()
{
    FILE *f1 = fopen("DFSMatsort.txt", "w");
    for (int k = 1; k <= 10; k++)
    {
        n = k;
        int adjMat[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adjMat[i][j] = 0;
            }
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                adjMat[i][j] = 1;
            }
        }
        opcount = 0;
        check(adjMat);
        fprintf(f1, "%d\t%d\n", n, opcount);
    }
    fclose(f1);
}

void main()
{
    int choice;
    printf("Enter\n 1.Tester\n 2.Plotter\n");
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
        printf("Invalid choice\n");
    }
}
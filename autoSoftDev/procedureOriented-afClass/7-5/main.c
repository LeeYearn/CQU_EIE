#include <stdio.h>

void check(int arr[][9], int value, int i, int j, int *count, int n, int m)
{
    if (i >= n || j >= m || arr[i][j] != value)
        return;
    (*count)++;
    arr[i][j] = -1;
    check(arr, value, i + 1, j, count, n, m);
    check(arr, value, i - 1, j, count, n, m);
    check(arr, value, i, j + 1, count, n, m);
    check(arr, value, i, j - 1, count, n, m);
}

void change(int arr[][9], int value, int i, int j, int n, int m)
{
    int count = 0;
    check(arr, value, i, j, &count, n, m);
    if (count >= 3)
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (arr[x][y] == -1)
                {
                    arr[x][y] = 0;
                }
            }
        }
    }
    else
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (arr[x][y] == -1)
                {
                    arr[x][y] = value;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 0)
                change(arr, arr[i][j], i, j, n, m);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j != m - 1)
                printf("%d ", arr[i][j]);
            else
            {
                if(j == m-1)printf("%d\n", arr[i][j]);
                else if(i==n-1)printf("%d", arr[i][j]);
            }
        }
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void align(int arr[50])
{
    for (int i = 1; i < strlen(arr); i++)
    {
        int indexFrist, indexSecond;
        if (arr[i] == '-')
        {
            if (arr[i - 2] == ' ')
                indexFrist = i - 1;
            else if (arr[i - 3] == ' ')
                indexFrist = i - 2;

            if (arr[i + 2] == ' ' || arr[i + 2] == '\n')
                indexFrist = i + 1;
            else if (arr[i + 3] == ' ' || arr[i + 3] == '\n')
                indexFrist = i + 2;
        }
    }
}

int main()
{
    char weekOld[50], week[50];
    int weekInt[20], len = 0;
    fgets(week, 100, stdin);
    strcpy(weekOld, week);
    char week1[2], week2[2];
    scanf("%s", week1);
    scanf("%s", week2);
    if (!strstr(week, week1) || (strstr(week, week1) && strstr(week, week2)))
        printf("not available\n");
    else
    {
    }
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%d*", weekInt[i]);
    // }
    printf("\n");
    return 0;
}

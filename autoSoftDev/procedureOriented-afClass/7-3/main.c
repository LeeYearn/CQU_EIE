#include <stdio.h>
#include <string.h>

int main()
{
    int line;
    scanf("%d", &line);
    getchar();

    for (int i = 0; i < line; i++)
    {
        char str[150];
        fgets(str, 150, stdin);
        int flag = 0;
        for (int j = 3; j < strlen(str); j++)
        {
            if ((str[j] == ',' || str[j] == '.') && str[j - 1] == 'g' && str[j - 2] == 'n' && str[j - 3] == 'o')
            {
                flag++;
            }
        }
        if (flag == 2 && strlen(str) > 8)
        {
            int count = 0;
            for (int j = strlen(str); j >= 0; j--)
            {
                if (str[j] == ' ' && strlen(str) > 3)
                {
                    if (count >= 2)
                    {
                        strcpy(&str[(j)], " qiao ben zhong.\n");
                        printf("%s", str);
                        break;
                    }
                    count++;
                }
            }
        }
        else
            printf("Skipped\n");
    }

    return 0;
}
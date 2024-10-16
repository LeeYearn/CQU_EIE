#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findPrime(int number)
{
    if (number < 2)
        return 0;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int length, len;
    scanf("%d %d", &length, &len);
    char str[length];
    scanf("%s", str);
    for (int i = 0; i <= length - len; i++)
    {
        char arr[255];
        strncpy(arr, str + i, len);
        int number = atoi(arr);
        if (findPrime(number))
        {
            printf("%0*d\n", len, atoi(arr));
            return 0;
        }
    }
    printf("404\n");
    return 0;
}
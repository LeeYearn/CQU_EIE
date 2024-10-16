#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findPrime(int number)
{
    if (number < 2)
        return 1;
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return 1;
    }
    return 2;
}

int findSame(int items[], int number)
{
    for (int i = 0; i < 1000; i++)
    {
        if (items[i] == number)
        {
            return i;
        }
    }
    return -1;
}

int sum(char arr[])
{
    int sum = 0;
    for (int i = 0; i < strlen(arr); i++)
    {
        sum += (arr[i] - '0') * (arr[i] - '0');
    }
    return sum;
}

int findHappy(int items[], int number, int *count)
{
    char arr[6];
    sprintf(arr, "%d", number);
    if (findSame(items, sum(arr)) != -1)
        return 0;
    items[*count] = sum(arr);
    if (items[*count] == 1)
        return ++(*count);
    (*count)++;
    findHappy(items, sum(arr), count);
}

int main()
{
    int A, B, index = 0;
    scanf("%d %d", &A, &B);
    int happy[20000];
    for (int i = A; i <= B; i++)
    {
        int count = 0, items[1000] = {0};
        if (findHappy(items, i, &count))
        {
            happy[index] = i;
            index += 1;
            happy[index] = count;
            index += 1;
        }
    }
    if (index > 0)
    {
        for (int i = 0; i < index; i += 2)
        {
            char arr[4];
            sprintf(arr, "%d", happy[i]);
            if (findSame(happy, sum(arr)) != -1)
            {
                happy[findSame(happy, sum(arr))] = -1;
                continue;
            }
        }
        for (int i = 0; i < index; i += 2)
        {
            if (happy[i] == -1)
                continue;
            printf("%d %d\n", happy[i], happy[i + 1] * findPrime(happy[i]));
        }
    }
    else
    {
        printf("SAD\n");
    }
    return 0;
}
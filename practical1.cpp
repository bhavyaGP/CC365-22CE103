#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    scanf("%s", str);
    int i = 0;
    while (i < strlen(str) && str[i] == 'a')
    {
        i++;
    }

    if (i + 1 < strlen(str) && str[i] == 'b' && str[i + 1] == 'b' && i + 2 == strlen(str))
    {
        printf("Valid String\n");
    }
    else
    {
        printf("Invalid String\n");
    }

    return 0;
}
#include <stdio.h>
int main()
{
    FILE *f1, *f2, *f3;
    int num, i;

    printf("\nData Input :\n\n");

    f1 = fopen("Vivek.txt", "w");

    for (i = 1; i <= 30; i += 1)
    {
        scanf("%d", &num);
        if (num == -1)
            break;

        putw(num, f1);
    }

    fclose(f1);

    f1 = fopen("Vivek.txt", "r");
    f2 = fopen("Odd.txt", "w");
    f3 = fopen("Even.txt", "w");

    while ((num = getw(f1)) != EOF)
    {
        if (num % 2 == 0)
            putw(num, f3);
        else
            putw(num, f2);
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);

    f2 = fopen("Odd.txt", "r");
    f3 = fopen("Even.txt", "r");

    printf("\n\n Odd File \n\n");

    while ((num = getw(f2)) != EOF)
        printf("%4d", num);

    printf("\n\n Even File \n\n");

    while ((num = getw(f3)) != EOF)
        printf("%4d", num);

    fclose(f2);
    fclose(f3);
    return 0;
}
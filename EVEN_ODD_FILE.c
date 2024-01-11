#include<stdio.h>

int main()
{
    FILE *f1, *f2, *f3;
    int num, i;

    f1 = fopen("int.txt", "w");
    printf("Enter the raw integer values (enter -1 to stop):\n\n");

    for (i = 1; i <= 30; i++)
    {
        scanf("%d", &num);
        if (num == -1)
            break;
        putw(num, f1);
    }
    fclose(f1);

    f1 = fopen("int.txt", "r");
    f2 = fopen("EVEN.txt", "w");
    f3 = fopen("ODD.txt", "w");

    while ((num = getw(f1)) != EOF)
    {
        if (num % 2 == 0)
            putw(num, f2);
        else
            putw(num, f3);
    }

    fclose(f1);
    fclose(f2);
    fclose(f3);

    f2 = fopen("EVEN.txt", "r");
    f3 = fopen("ODD.txt", "r");

    printf("\n\nEven File Data\n\n");
    while ((num = getw(f2)) != EOF)
    {
        printf("%d ", num);  // Added space after each number
    }

    printf("\n\nOdd File Data\n\n");
    while ((num = getw(f3)) != EOF)
    {
        printf("%d ", num);  // Added space after each number
    }

    fclose(f2);
    fclose(f3);

    return 0;
}

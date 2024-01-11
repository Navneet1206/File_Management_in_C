#include <stdio.h>
int main()
{

    FILE *sf, *df;
    char ch;

    sf = fopen("source.txt", "w");

    printf("Input Data in source file (For exit from Source file press ^z ^z ):\n");

    if (sf == NULL)
    {
        printf("File Not Found there is an error :");
        return 1;
    }

    while ((ch = getchar()) != EOF)
    {
        putc(ch, sf);
    }

    fclose(sf);

    sf = fopen("source.txt", "r");
    df = fopen("destination.txt", "w");

    if (df == NULL)
    {
        printf("File not found");
        fclose(sf);
        return 2;
    }

    while ((ch = getc(sf)) != EOF)
    {
        putc(ch, df);
    }
    fclose(sf);
    fclose(df);

    df = fopen("destination.txt", "r");
    printf("Copied Data from source File : \n");

    while ((ch = getc(df)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(df);

    return 0;
}
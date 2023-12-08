#include<stdio.h>
int main()
{
    FILE *f1;
    char c;

    printf("Data input \n\n");

    f1=fopen("Index.html","w");

    while((c=getchar())!=EOF)

    putc(c,f1);

    fclose(f1);

    printf("\n\nData Output\n\n");

    f1=fopen("Index.html","r");

    while((c=getc(f1))!=EOF)
    printf("%c",c);

    fclose(f1);
    return 0;
}
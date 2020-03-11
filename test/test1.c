#include <stdio.h>
#include <stdlib.h>
void swap1(int *a,int *b);
void swap2(int *a,int *b);
int main(int argc, char const *argv[])
{
    int a = 10,b = 15;
    swap1(&a,&b);
    printf("%d,%d\n",a,b);//10 15
    a = 10,b = 15;
    swap2(&a,&b);
    printf("%d,%d\n",a,b);//15 10
    system("pause");
    return 0;
}
void swap1(int *a,int *b)
{
    int *c = a;
    a = b, b = c;
}
void swap2(int *a,int *b)
{
    int c = *a;
    *a = *b, *b = c;
}

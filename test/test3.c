#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int a,b,c,d;
    a = 10;
    b = a++;//10
    c = ++a;//12
    d = 10 * a++;//120 从左到右
    printf("b,c,d:%d,%d,%d\n",b,c,d);
    system("pause");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    int x = 05;
    char z = 'a';
    printf("%d\n",(x&1)&&(z<'z'));//1
    system("pause");
    return 0;
}

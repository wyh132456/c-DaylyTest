#include <stdio.h>
#include <stdlib.h>
void abc(char *str);
int main(int argc, char const *argv[])
{
    char str[] = "abcdef";
    abc(str);
    printf("str[] = %s\n",str);
    system("pause");
    return 0;
    
}
//str[b++] = 'a';str[b++] = 'b';str[b++] = 'd';str[b++] = 'f';
void abc(char *str)// abdef
{
    int a,b;
    for(a = b = 0;str[a]!='\0';a++)
    {
        if(str[a] != 'c')
        {
            str[b++] = str[a];
        }
    }
    str[b] = '\0';
}
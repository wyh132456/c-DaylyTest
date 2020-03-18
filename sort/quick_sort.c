#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10
#define SWAP(a,b) {int tmp;tmp = a;a = b;b = tmp;}
//分割函数
int partition(int *arr,int left,int right)
{
//最后一个元素作为分割点,比分割点大的不变,小的放前面
    int i,k;
    for(i = k = left;i < right;i ++)
    {
        if(arr[i]<arr[right])
        {
            SWAP(arr[i],arr[k]);
            k++;
        }
    }
    SWAP(arr[k],arr[right]);
    return k;
}


void arr_quick(int *arr,int left,int right)
{
    int pivot = 0;//分割点
    if(left < right)
    {
      pivot = partition(arr,left,right);
      arr_quick(arr,left,pivot-1);
      arr_quick(arr,pivot+1,right);
    }
}
void arr_print(int *arr)
{
    int i;
    for (i = 0;i < N; i++)
    {
        printf("%3d ",arr[i]);
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    int arr[N] = {0};
    int i;
    srand(time(NULL));//得到随机种子
    for(i = 0;i < N;i++)
    {
        arr[i] = rand()%100;
    }
    arr_print(arr);
    arr_quick(arr,0,N-1);
    arr_print(arr);
    system("pause");
    return 0;
}

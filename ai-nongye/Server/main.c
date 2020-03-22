#include "main.h"


int main(int argc, char const *argv[])
{
    //主程负责打开数据库,创建消息队列,创建信号量，创建子进程









    pid_t pid;
    int i = 0;
    for(i = 0;i < 3;i++)//创建三个子进程
    {
        pid = fork();
        if(pid == -1)
        {
            perror("fork error!");
            exit(1);
        }
        if(pid == 0)//避免子进程再次fork
        break;
    }
    if(i == 0)//子进程1
    {

    }
    else if(i == 1)//子进程2
    {

    }
    else if(i == 2)//子进程3
    {

    }
    else if(pid > 0)//父进程
    {

    }
    return 0;
}

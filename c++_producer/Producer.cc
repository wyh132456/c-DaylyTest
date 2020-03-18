#pragma once 
#include "Producer.h"
#include "TaskQueue.h"
#include <unistd.h>
#include <stdlib.h>

using std::cout;
using std::endl;

namespace wd
{
    //先生产数据 再放到缓冲队列里面去
    void Producer::run()
    {
        ::srand(::clock());
        int cnt = 10;
        while(cnt--)
        {
            int number = ::rand()%100;
            _que.push(number);
            cout <<"producer thread" << pthread_self()
                 <<":producer a number = " << number << endl;
                 ::sleep(1);  
        }

    }
}
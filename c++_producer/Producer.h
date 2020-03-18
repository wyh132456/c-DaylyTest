#pragma once
#include"Thread.h"
#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using stg::queue;

namespace wd
{
    class TaskQueue;
    class producer
    :public Thread
{
public:
    producer(TaskQueue & que)
    : _que(que)
    {}
private:
    void run();
private:
    TaskQueue & _que;
};
}//end of namesapce 

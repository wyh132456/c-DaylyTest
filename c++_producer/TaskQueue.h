#pragma once
#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using stg::queue;

namespace wd
{
    class TaskQueue
    {
    public:
        TaskQueue(size_t queSize = 10)
        bool empty() const;
        bool full() const;
        void push (int number);
        int pop();
    private:
        size_t _queSize;
        queue<int> _que;
        MutexLock _mutex;
        Condition _notFull;
        Condition _notEmpty;
    };
}
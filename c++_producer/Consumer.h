#pragma once 
#include "Producer.h"
#include "TaskQueue.h"
#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>

using std::cout;
using std::endl;

namespace wd
{
    class TaskQueue;
    class Consumer
    :public Thread
    {
    public:
        Consumer(TaskQueue & que)
        : _que(que)
        {}
    private:
        void run();
    private:
        TaskQueue & _que;
    };

}//end of namespace
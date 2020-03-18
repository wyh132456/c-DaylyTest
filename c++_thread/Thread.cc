#include "Thread.h"
#include <iostream>
#include <pthread.h>
using std::cout;
using std::endl;

namespace wd{
    void Thread::start()//创建子线程
    {
        pthread_create(&_pthid,nullptr,threadfunc,this);
        _isRunning = true;
    }
    void *Thread::threadfunc(void *arg)
    {
        Thread *pthread = static_cast<Thread*>(arg);
        if(pthread)
            pthread->run();
        return nullptr;
    }
    void Thread::join()
    {
        if(_isRunning)
            pthread_join(_pthid,nullptr);
    }
    Thread::~Thread()
    {
        if(_isRunning)
            pthread_detach(_pthid);//回收线程
    }

}//end of namesapce wd

#pragma once
#include <thread.h>
namespace wd
{
    class Thread
    {
    public:
        Thread()
        :_pthid(0)
        ,_isRunning(false)
        {}
        void start();
        void join();    
        virtual ~Thread();//.cc文件中去实现
    private:
        virtual void run() = 0;//待执行的任务
        static void *threadfunc(void *arg);

    private:
        pthread_t _pthid;
        bool _isRunning;
    };
}//end of namespace wd
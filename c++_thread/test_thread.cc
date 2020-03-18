#include "Thread.h"
#include <iostream>
#include <memory>
#include <stdlib.h>
#include <time.h>
using std::cout;
using std::endl;
using std::unique_ptr;
class MyThread
:public wd::Thread{
    void run()
    {
        ::srand(::clock());
        int cnt = 20;
        while (cnt --)
        {
            int num = ::rand()%100;
            cout << "sub Thread "<< pthread_self()
            << ": number ="<< number << endl;
            ::sleep(1);
        }
    }
};

int main(int argc, char const *argv[])
{
    unique_ptr<wd::Thread> thread(new MyTHread());
    thread->start();
    //thread->run();//子线程,代表执行的任务
    thread->join();
    return 0;
}

#include"mutex_condition.h"
using std::cout;
using std::endl;

int tickets = 1000;
bool flag = true;
wyh::MutexLock mutex;
wyh::Condition cond(mutex);
//两个线程交替去卖票
void *threadfun1(void *arg)
{//1号窗口,当flag为true时,卖票
    int cnt = 100;
    while(cnt --)
    {
    mutex.lock();
    if(!flag){ //当flag为false的时候,不能卖票,所以窗口只能等
        cond.wait();
    }
    //开始卖票
    --tickets;
    if(flag)
    {
        flag = false;
        cond.notify();//通知线程2卖票
    }
    mutex.unlock();
    }
    return nullptr;
}
void *threadfun2(void *arg)
{//2号窗口,当flag为false时,卖票
    int cnt = 100;
    while(cnt --)
    {
    mutex.lock();

    mutex.unlock();
    }
    return nullptr;
}
int main(int argc, char const *argv[])
{
    pthread_t pthid1,pthid2;
    pthread_create(&pthid1,nullptr,threadfun1,nullptr);
    pthread_create(&pthid1,nullptr,threadfun1,nullptr);

    pthread_join(pthid1,nullptr);
    pthread_join(pthid2,nullptr);
    return 0;
}

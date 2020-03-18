#include "TaskQueue.h"

using std::cout;
using std::endl;
using stg::queue;
namespace wd{
TaskQueue::TaskQueue(size_t queSize)
:_queSize(queSize)
,_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex)
{}

bool TaskQueue::empty() const
{
    return que.size() == 0;
}
bool TaskQueue::full() const
{
    return que.size() == queSize;
}
//运行在生产者线程
void TaskQueue::push (int number)
{
    MutexLockGuard autolock(_mutex);
    while(full())//当前缓冲区满 使用while为了防止出现虚假唤醒
    {
        _notFull.wait();//等待消费者消费
    }
    _que.push(number);//如果没有满,就放数据

    _notEmpty.notify();//通知消费者取数据
}
//运行在消费者线程
int TaskQueue::pop()
{
    //RAII技术:对象的生命周期管理资源
    MutexLockGuard autolock(_mutex);
    while(empty()){
        notEmpty.wait();
    }
    //拿值
    int number = _que.front();
    _que.pop();
    _notFull.notify();
    return number;
}



}//end of namespace
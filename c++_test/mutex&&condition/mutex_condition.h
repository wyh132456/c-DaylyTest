//封装互斥锁与条件变量
//在调用pthread_cond_wait()之前,先要加锁,调用pthread_cond_wait时
//阻塞当前线程A 在阻塞线程A之前,先要解锁
//当另外一个线程B唤醒条件变量时,当前线程A要再加锁才可以往下执行

#pragma once
#include <iostream>
#include <pthread.h>
#include <stdio.h>
#include <>
#include <stdlib.h>
using std::cout;
using std::endl;

namespace wyh
{
class MutexLock
{
    public:
        MutexLock()
        :_isLocking(false);
        {
            if(pthread_mutex_init(&_mutex,nullptr))
                perror("pthread_mutex error!");
        }

        ~MutexLock()
        {
            if(pthread_mutex_destroy(&_mutex))
                perror("pthread_mutex_destory error!");

        }
    public:
        void lock()
        {
            if(pthread_mutex_lock(&_mutex)){
                perror(" pthread_mutex_lock error!");
            }
            _isLocking = true; 

        }
        void unlock()
        {
            if(pthread_mutex_unlock(&_mutex)){
                perror(" pthread_mutex_unlock error!");
            }
            _isLocking = false;
        }

        bool isLocking() const
        {
            return _isLocking;
        }
        pthread_mutex_t * getMutexLockPtr//得到互斥锁的地址传给条件变量
        {
            return &_mutex;
        }
    private:
        pthread_mutex_t _mutex;
        bool _isLocking;
}

class Condition
{
    public:
        Condition(MutexLock & mutex)
        : _mutex(mutex)
        {
            if(pthread_cond_init(& _cond,nullptr)){
                perror("pthread_cond_init");
            }
        }
        ~Condition()
        {
            if(pthread_cond_destroy(&_cond)){
                perror("pthread_cond_desroty");
            }
        }
    public:
        void wait()//阻塞当前线程,调用wait之前先要加锁
        {
            if(pthread_cond_wait(&_cond, _mutex.getMutexLockPtr()));//传入互斥锁的地址
            {
                perror("pthread_cond_wait");
            }
        }
        void notify()//通知某一个线程
        {//wait是一个线程而notify是另一个线程
            if(pthread_cond_signal(&_cond))
            {
                perror("pthread_cond_signal");
            }
        }
        void notifyall()//广播通知
        {
            if(pthread_cond_broadcast(&_cond))
            {
                perror("pthread_cond_broadcast");
            }
        }
    private:
        MutexLock & _mutex;//只与wait单向联系
        pthread_cond_t _cond;
}
}//end of namesapce;
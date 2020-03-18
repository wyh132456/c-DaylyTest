#include "Consumer.h"
#include "Producer.h"
#include "TaskQueue.h"
#include "Thread.h"
#include <unistd.h>
#include <stdlib.h>

using std::cout;
using std::endl;

namespace wd
{
   void Consumer::run()
   {
       int cnt = 10;
       while(cnt --)
       {
           int number = _que.pop();
           cout << "consumer thread" << pthread_self()
                << ": comsumer a number =" << number << endl;
           ::sleep(1);
       }
   }

}//end of namespace
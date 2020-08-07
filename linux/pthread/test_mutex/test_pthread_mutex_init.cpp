/*************************************************************************
  > File Name: test_condition.cpp
  > Author: cxxxxf
  > Mail: sophistcxf@gmail.com
  > Created Time: 2016年10月25日 星期二 14时46分30秒
 ************************************************************************/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t wait_mutex;

void* thread_cb1(void* param);
void* thread_cb2(void* param);

void insight_pthread_mutexattr_t()
{

}

int main()
{
  pthread_t p2;
  pthread_create(&p2, NULL, thread_cb2, NULL);
  pthread_t p1;
  pthread_create(&p1, NULL, thread_cb1, NULL);
  pthread_join(p1, NULL);
  pthread_join(p2, NULL);
  return 0;
}

void* thread_cb1(void* param)
{
  pthread_mutex_lock(&wait_mutex);
  pthread_mutex_unlock(&wait_mutex);
}

void* thread_cb2(void* param)
{
  pthread_mutex_lock(&wait_mutex);
  printf("I'm thread_cb2, %d\n", num++);
  pthread_mutex_unlock(&wait_mutex);
}

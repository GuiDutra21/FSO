#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int count = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
struct thread_arg {
int vezes
};

int work(int id);

void *thread_func(void *arg)
{   
    int id;
    struct thread_arg *vezes = arg;
    for(int i = 0; i < vezes->vezes;i++)
    {
        pthread_mutex_lock(&mut);
        count++;
        id = count;
        pthread_mutex_unlock(&mut);
        work(id);
    }
}
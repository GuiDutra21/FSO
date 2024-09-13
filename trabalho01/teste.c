#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

struct thread_arg
{
    int num;
};

void *thread_func(void *arg)
{
    struct thread_arg *ctx = arg;
    printf("Hello, world %d\n", ctx->num);
    pthread_exit(NULL);
}

int main(void)
{

    int ret, i;
    pthread_t threads[5];
    struct thread_arg args[5];

    for(i=0; i < 5; i++)
        args[i].num = i;

    for (i = 0; i < 5; i++)
    {

        printf("Criando a Thread %d\n", i);
        ret = pthread_create(&threads[i], NULL, &thread_func, &args[i]);

        if (ret)
        {
            printf("erro %d na thread %d\n", ret, i);
            perror("pthread_create\n");
            exit(-1);
        }
    }

    pthread_exit(NULL);
}
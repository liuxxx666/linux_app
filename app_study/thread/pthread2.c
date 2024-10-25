#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void *thr_fn1(void *arg)
{
    printf("thread1 returning\n");
    return ((void *)1);
}

void *thr_fn2(void *arg)
{
    printf("thread1 pthread_exiting\n");
    pthread_exit((void *)2);
}

int main(void)
{
    int err;
    pthread_t tid1, tid2;
    void *tret;
    
    err = pthread_create(&tid1, NULL, thr_fn1, NULL);

    err = pthread_create(&tid2, NULL, thr_fn2, NULL);

    err = pthread_join(tid1, &tret);
    printf("pthread1 return code %ld\n", (long)tret);

    err = pthread_join(tid2, &tret);
    printf("pthread2 return code %ld\n", (long)tret);

    exit(0);
}



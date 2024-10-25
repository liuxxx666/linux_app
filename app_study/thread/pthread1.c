#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

pthread_t ntid;

void print_tids(char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf("%s pid %lu tid %lu (0x%lx)\n", s, 
        (unsigned long)pid, (unsigned long)tid,
        (unsigned long)tid);
}

void *pthread_fn(void *arg)
{
    print_tids("new thread: ");

    return ((void *)0);
}

int main(void)
{
    int err;

    err = pthread_create(&ntid, NULL, pthread_fn, NULL);
    if(err) 
        exit(-1);

    print_tids("main thread: ");

    sleep(1);

    exit(0);
}
#include <stdio.h>
#include <pthread.h>

void *show(void *value){
    sleep(1);
    int *i = (int*)value;
    printf("Thread %d print message\n", *i);
    pthread_exit(0);                                //we exit the thread
    return NULL;
}

int main() {
    int n = 8;                                       // program runs N threads that is in our case is equal to 8
    pthread_t threadID;
    for(int i=0; i<n; i++){
        pthread_create(&threadID, NULL, show, &i);   //We create the thread with Id, and function where we write that will done by a thread
                                                     //the last parameter is the value that we want to give to a function show
        printf("Thread %d created\n", i);
        pthread_join(threadID, NULL);                //function for threads is the equivalent of wait() for processes. A call to pthread_join
                                                     //blocks the calling thread until the thread with identifier equal to the first argument terminates
        printf("Tread %d exited\n", i);

    }
    return 0;
}

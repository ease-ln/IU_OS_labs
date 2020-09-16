#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
//Capacity of the buffer
#define N 20
//buffer with capacity of 20
char buffer[N];
//counter, how much in buffer is busy
int counter = 0;
//checker for threads state
int bConsumerSleeping ,bProducerSleeping;
//launcher for timer;
int t = 0;

void *pro(void *ptr) {
    //infinity loop
    while(1) {
        //if state for producer is sleep than wait
        if(bProducerSleeping)
            continue;
        //if buffer is full than change producer state to sleep
        if(counter == N) {
            bConsumerSleeping = 0;
            bProducerSleeping = 1;
            //if t = 1 print 1 (means that every 60 sec we print 1 if program still works)
            if(t){
                printf("1\n");
            }
            t = 0;
            continue;
        }
        //add data to buffer and increment counter(means that there are one more data in the buffer)
        buffer[counter] = 'a';
        counter++;
        //sleep(10);   <- for slow downing the speed of producer, so deadlock will occure slower
    }

    pthread_exit(NULL);
    return NULL;
}

void *con(void *ptr) {
    //infinity loop
    while (1) {
        //if state for consumer is sleep than wait
        if(bConsumerSleeping)
            continue;
        //if buffer is empty than change consumer state to sleep
        if(counter == 0) {
            bConsumerSleeping = 1;
            bProducerSleeping = 0;
            continue;
        }
        //decrement the counter(means on 1 data less in buffer)
        counter--;
        //sleep(10);   <- for slow downing the speed of consumer, so deadlock will occure slower

    }
    pthread_exit(NULL);
    return NULL;
}

void *timert(void *ptr){
    //infinity loop
    while(1){
        //sleep for 60 sec and change launcher to 1
        sleep(60);
        t = 1;
    }
}


int main(){
    bConsumerSleeping=1;

    pthread_t producer, consumer, timer;
    pthread_create(&timer, NULL, timert, NULL);
    pthread_create(&producer, NULL, pro, NULL);
    pthread_create(&consumer, NULL, con, NULL);

    while(1);
    return 0;
}

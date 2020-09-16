#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define N 10
int count = 0;
int max = N;
char buffer[N];

void* producer_t(void* args){
    while(1){
        //if there a empty space produce item
        if(count < max){
            count++;
            buffer[count]='p';
            //if there no space wait
        } else {
            while(count==max){
            }
        }
    }
}

void* consumer_t(void* args){
    while(1){
        //if there anything to grab then grab
        if(count > 0){
            buffer[count]='c';
            count--;
        } else {
            //If there nothing to grab just wait
            while(count==0){

            }
        }

    }
}

void* timer_th(void* args){
    while(1){
        sleep(60);
        printf("1\n");
    }
}

int main(){
    pthread_t producer, consumer, timer;
    pthread_create(&producer, NULL, producer_t, NULL);
    pthread_create(&consumer, NULL, consumer_t, NULL);
    pthread_create(&timer, NULL, timer_th, NULL);
    pthread_exit(NULL);
    return 0;
}

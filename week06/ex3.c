#include <stdio.h>
#include <stdlib.h>
/*
the average turnaround and waiting time in round robin
 is less comparing to the FCFS and SJF
 FCFS is better for a small burst time. 
 The SJF is better if the process comes to processor simultaneously.
 Round Robin is better to adjust the average waiting time desired.
*/

/* Round robin implementation
q   = quantum
id  = process ID
at  = arrival time
bt  = burst time
ct  = complete time = exit time
wt  = waiting time
tat = turnaround time
rm  = remaining burst time
atat = average turnaround time
awt  = average waiting time
Algorithm:  1. Sort stable processes by arrival time with respect to id
            2. Compute et
            3. Compute wt, tat, atat, awt
Example used: n = 3 at/bt: 2/4 3/6 1/4
*/
struct process{
   int id;
   int at;
   int bt;
   int ct;
   int wt;
   int tat;
   int rm;
};
//Comparator for qsort by arrival time with respect to id
int comparator(const void *p, const void *q)
{
    struct process *pa = (struct process *) p;
    struct process *pb = (struct process *) q;
    int res = pa->at - pb->at;
    return res != 0 ? res : pa->id - pb->id;
}
/*We assume that the q, n, at, bt positive integer
 numbers by task conditions and lecture examples*/
int main(){
    int n = 0;
    int quan = 0;
    float atat = 0;
    float awt = 0;
    //q[n] represent the queue
    int q[n];

    printf("Enter number of processes:");
    scanf("%d", &n);

    printf("Enter quantum:");
    scanf("%d", &quan);

    /*if(n<0){
        printf("n can not be less than 0");
        return 0;
    }*/

    printf("Enter Arrival(AT) and Burst(BT) time for each process:\n");
    struct process pro[n];

    for(int i = 0; i < n; ++i){
    pro[i].id = i+1;
    printf("AT of process[%d]:", i);
    scanf("%d", &pro[i].at);
        if(pro[i].at<0){
        printf("AT can not be less than 0");
        return 0;
        }
    printf("BT of process[%d]:", i);
    scanf("%d", &pro[i].bt);
    pro[i].rm = pro[i].bt;
        if(pro[i].bt<0){
        printf("BT can not be less than 0");
        return 0;
        }
    }
    //qsort by arrival time with respect to id
    qsort(pro, n, sizeof(struct process), comparator);

    //Initialize every element of q to -1
    for(int i = 0; i < n; i++){
        q[i] = -1;
    }

    //Simulation of round robin process
   int temp=0;
   int t = pro[0].at;
    int tq = 0;
    while(tq !=1){
            tq = 1;
        for(int i = 0; i < n; i++){
            if(t >= pro[i].at && pro[i].rm>0){
                if(pro[i].rm>quan){
                    temp = quan;
                } else {
                    temp = pro[i].rm;
                }
                pro[i].rm-=temp;
                q[i] = pro[i].rm;
                t+=temp;
                if(q[i]==0){
                pro[i].ct = t;
                pro[i].tat = pro[i].ct - pro[i].at;
                pro[i].wt  = pro[i].tat -pro[i].bt;
                atat = atat + pro[i].tat;
                awt = awt + pro[i].wt;
                }

            } else if(q[i]>0){
                pro[i].rm-=temp;
                q[i] = pro[i].rm;
                t+=temp;
                if(q[i]==0){
                pro[i].ct = t;
                pro[i].tat = pro[i].ct - pro[i].at;
                pro[i].wt  = pro[i].tat -pro[i].bt;
                atat = atat + pro[i].tat;
                awt = awt + pro[i].wt;
                }
            } else if(q[i]<=0){
                continue;
            }
            for(int k = 0; k < n; k++){
                if(q[k]!=0){tq=0;}
            }
        }
    }


//Result printing
    printf("ID\t    AT\t    BT\t    CT\t    TAT\t    WT\t\n");
    for (int i = 0; i < n; ++i)
    printf("%d\t     %d\t     %d\t     %d\t     %d\t      %d\t\n", pro[i].id, pro[i].at, pro[i].bt, pro[i].ct, pro[i].tat, pro[i].wt);
    printf("Average Turnaround time: %f\n", atat/n);
    printf("Average Waiting time: %f\n", awt/n
           );
    return 0;
}

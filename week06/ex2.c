#include <stdio.h>
#include <stdlib.h>
/* First come, first served implementation
id  = process ID
at  = arrival time
bt  = burst time
ct  = complete time
wt  = waiting time
tat = turnaround time
atat = average turnaround time
awt  = average waiting time
Algorithm:  1. Sort stable processes by brust time
            2. Sort stable processes by arrival time
            2. Compute ct, wt, tat, atat, awt
Example used: n = 3
              at/bt: 2/4 3/6 1/4
*/
//process structure
struct process{
   int id;
   int at;
   int bt;
   int ct;
   int wt;
   int tat;
};
//Comparator for brust time with respect to process id
int comparator(const void *p, const void *q)
{
    struct process *pa = (struct process *) p;
    struct process *pb = (struct process *) q;
    int res = pa->bt - pb->bt;
    return res != 0 ? res : pa->id - pb->id;
}
//Comparator for arrival time with respect to process brust time
int comparator0(const void *p, const void *q)
{
    struct process *pa = (struct process *) p;
    struct process *pb = (struct process *) q;
    int res = pa->at - pb->at;
    return res != 0 ? res : pa->bt - pb->bt;
}
/*We assume that the n, at, bt positive integer
 numbers by task conditions and lecture examples*/
int main(){
    int timer = 0;

    int n = 0;
    printf("Enter number of processes:");
    scanf("%d", &n);
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
        /*if(pro[i].at<0){
        printf("AT can not be less than 0");
        return 0;
        }*/
    printf("BT of process[%d]:", i);
    scanf("%d", &pro[i].bt);
        /*if(pro[i].bt<0){
        printf("BT can not be less than 0");
        return 0;
        }*/
    }
    //qsort for brust time with respect to process id
    qsort(pro, n, sizeof(struct process), comparator);
    //qsort for arrival time with respect to process brust time
    qsort(pro, n, sizeof(struct process), comparator0);


    timer = pro[0].at;

    float atat = 0;
    float awt = 0;
    ////Computing ct, wt, tat, atat, awt
    for (int i = 0; i < n; ++i){
            pro[i].ct = timer+pro[i].bt;
            timer = pro[i].ct;
            pro[i].tat = pro[i].ct - pro[i].at;
            pro[i].wt  = pro[i].tat -pro[i].bt;
            atat = atat + pro[i].tat;
            awt = awt + pro[i].wt;

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

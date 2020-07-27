#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
// struct proc_stat{
//   int pid;                  // PID of each process
//   float runtime;            // Use suitable unit of time
//   int num_run;              // number of time the process is executed
//   int current_queue;        // current assigned queue
//   int ticks[5];             // number of ticks each process has received at each of the 5 priority queue
// };
int main(int argc,char const *argv[])
{   
    if(argc!=2)
    {   printf(2,"error with parameters\n");
        exit();
    }
    // int wtime,rtime;
    // waitx(&wtime,&rtime);
    // printf(1,"wtime = %d, rtime = %d\n",wtime,rtime);
    struct proc_stat *ps=malloc(sizeof(struct proc_stat));
    int pid;
    pid = atoi(argv[1]);
    getpinfo(ps,pid);
    printf(1,"proc stat:\n pid = %d \t current_queue = %d \t num_run = %d\n",ps->pid,ps->current_queue,ps->num_run);
    for(int i=0;i<5;i++)
        printf(1,"ticks[%d] = %d\n",i,ps->ticks[i]);
    exit();
}
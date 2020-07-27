#include "types.h"
// #include "defs.h"
// #include "param.h"
// #include "memlayout.h"
// #include "mmu.h"
// #include "x86.h"
// #include "proc.h"
// #include "spinlock.h"
#include "stat.h"
#include "user.h"
int main()
{   int wtime,rtime;
    // waitx(&wtime,&rtime);
    // printf(1,"wtime = %d, rtime = %d\n",wtime,rtime);
    int pid = fork();
    if(pid == 0)
    {
        printf(1,"child created \n");
        sleep(20);
    }
    else if(pid>0)
    {   waitx(&wtime,&rtime);
    }
    
    exit();
}
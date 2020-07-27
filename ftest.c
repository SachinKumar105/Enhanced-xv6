#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "pstat.h"

void
t(int l)
{   
    int x=0; 
    for(int i=0;i<l*10000000;i++){
        x++;x--;
        printf(1,"");
    }
}
int
main(void)
{   struct proc_stat *ps=malloc(sizeof(struct proc_stat));
    for(int i=0;i<5;i++)
    {   int pid=fork();
        if(pid==0)
        {
            switch (i)
            {
                case 1:
                    chpr(getpid(),90);
                    t(3);
                break;
                case 2:
                    chpr(getpid(),80);
                    t(4);
                break;  
                case 3:
                    chpr(getpid(),65);
                    t(5);
                break;
                case 4:
                    chpr(getpid(),70);
                    t(6);
                break;
                default:
                    chpr(getpid(),85);
                    t(7);
                break;
            }
            cps();
            getpinfo(ps,getpid());
            printf(1,"proc stat:\n pid = %d \t current_queue = %d \t num_run = %d\n",ps->pid,ps->current_queue,ps->num_run);
            for(int i=0;i<5;i++)
                printf(1,"ticks[%d] = %d\n",i,ps->ticks[i]);
            exit();   
        }
        

    }
    for(int i=0;i<5;i++)
    {
        int wtime,rtime;
            waitx(&wtime,&rtime);
    }
    exit();
}
// #include"types.h"
// #include"stat.h"
// #include"user.h"
// #include"fcntl.h"

// void timewaste(int n){
//     int x =0;
//     for (int i = 0; i < n*1000000; i++)
//     {
//         x++;
//         x--;
//         printf(1,"");
//     }
    
// }
// int 
// main(int argc, char const *argv[])
// {  
//     // #if FCFS
//     //     printf(1,"FCFS\n");
//     // #else 
//     // #if DEFAULT
//     //     printf(1,"DEFAULT\n");
//     // #else 
//     // #if PBS
//     //     printf(1,"PBS\n");
//     // #endif
//     // #endif
//     // #endif
//     for(int i=0;i<4;i++){
//         int pid = fork();
//         if(pid==0){
//             switch (i)
//             {
//             case 1:
//                 chpr(getpid(),90);
//                 timewaste(4);
//                 // set_priority(getpid(),100);
//                 break;
//             case 2:
//                 chpr(getpid(),80);
//                 timewaste(3);
//                 // set_priority(getpid(),90);
//                 break;
//             case 3:
//                 chpr(getpid(),65);
//                 timewaste(5);
//                 // set_priority(getpid(),80);
//                 break;   
//             default:
//                 chpr(getpid(),70);
//                 // set_priority(getpid(),70);
//                 timewaste(3);
//                 break;
//             }
//             cps();
//             exit();
//         }
//     }
//     for (int i = 0; i < 4; i++)
//     {   
//         int a, b;
//         waitx(&a,&b);
//     }
//     exit();
// }
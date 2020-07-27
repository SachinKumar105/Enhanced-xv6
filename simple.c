#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int i;

  if(argc <= 1){
    printf(1, "Usage: %s words\n",argv[0]);
    exit();
  }

  for(i = 1; i < argc; i++){
    // if((fd = open(argv[i], 0)) < 0){
    //   printf(1, "wc: cannot open %s\n", argv[i]);
    //   exit();
    // }
    printf(1,"%s", argv[i]);
    // close(fd);
  }
    printf(1,"\n");
  exit();
}

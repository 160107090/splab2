// your code here
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  printf("(%d) line8\n", getpid());
  int pid = fork(); 
  printf(" (%d) line10\n", getpid());
  
  //child1
  if (pid ==0){ 
           printf("(%d) line14\n", getpid());
           execlp("python","python", "add.py" argv[1], argv[2], NULL);
           printf("(%d) line16......exec failed\n", getpid());
  } else //parent
  { 
    printf("(%d) line19\n", getpid());
    int pid2 = fork();
    printf("(%d) line21\n", getpid());
    if (pid2 == 0){ //child 2
      printf("(%d) line23\n", getpid());
      execlp("./div.sh" , ":", argv[1], argv[2], NULL);
      printf("(%d) line25 .....exec failed\n", getpid());
    } else //parent
    { 
           printf("(%d) line28\n", getpid());   
           wait(0);
           wait(0);
           printf( "parent: done\n");
    }
  }
}
  
  

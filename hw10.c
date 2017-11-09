#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    //placeholder
    printf("received SIGINT\n");
    exit(1);
  }
  if(signo == SIGUSR1){
    printf("Received SIGUSR1. PID of parent process: %d \n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);

  while(1){
    printf("PID: %d \n", getpid());
    sleep(1);
  }

  return 0;
}

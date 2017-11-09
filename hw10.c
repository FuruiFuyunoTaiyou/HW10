#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    int fd = open("msgs", O_WRONLY | O_APPEND | O_CREAT, 0644);
    write(fd, "received SIGINT. \n", sizeof("received SIGINT. \n"));
    close(fd);
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

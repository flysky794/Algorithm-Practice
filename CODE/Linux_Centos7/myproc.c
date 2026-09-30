#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{
  pid_t pid = fork();
  if(pid == 0)
  {
    //child
    int cnt = 5;
    while(cnt--)
    {
      printf("我是一个子进程：pid：%d\n", getpid());
      sleep(1);
    }
    exit(0);
  }
  else if(pid > 0)
  {
    sleep(10);
    pid_t rpid = wait(NULL);
    if(rpid == pid)
    {
      printf("pid：%d, wait success!\n", getpid());
    }
    sleep(5);
    exit(0);
  }
}

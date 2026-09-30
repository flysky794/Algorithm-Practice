#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

void Task()
{
  std::cout << "执行任务" << std::endl;
  sleep(3);
}

void CreatChildProcess(const int num, std::vector<pid_t> *subs)
{
  for(int i = 0; i < num; ++i)
  {
    pid_t id = fork();
    if(id == 0)
    {
      Task();
      exit(0);
    }
    else if(id > 0)
    {
      //父进程
      subs->push_back(id);
    }
    else
    {
      perror("fork");
    }
  }
}

void WaitAllSubs(const std::vector<pid_t> &subs)
{

  for(auto &sub : subs)
  {
    int status = 0;
    pid_t rid = waitpid(sub, &status, 0);
    if(rid > 0)
    {
      sleep(5);
      printf("SubProc: %d Exit, Exit code: %d\n", rid, (status>>8)&0x7F);
    }
  }

}

enum
{
  OK,
  USAGE_ERR
};



int main(int argc, char *argv[])
{

  if(argc < 2)
  {
    std::cout << "Usage：" << argv[0] << " process_num" << std::endl;
    exit(USAGE_ERR);
  }
  //父进程
  int num = std::stoi(argv[1]);
  std::vector<pid_t> subs;
  //创建多个进程
  CreatChildProcess(num, &subs);
  //等待回收子进程
  WaitAllSubs(subs);
  sleep(5);
  return OK;
}

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>
#include <cstdio>




int main(int argc, char** argv)
{
  printf("hello\n");
  pid_t parent = getpid();
  pid_t pid = fork();
  printf("\npid:%d\n",pid);
  if (pid == 0)
  {
    //KEY PART
    //setpgid(getpid(), getpid());

    //system("roslaunch --core");
    //execl("/opt/ros/melodic/bin/roslaunch", "HAHAHA", "--core", NULL);
    execl("/usr/bin/python", "HAHAHA" ,"/opt/ros/melodic/bin/roslaunch", "--core", NULL);
    printf("XXXXX pid:%d pgid:%d\n", getpid(), getpgid(getpid()));
    //system("./tool/talker");
    //system("./tool/talker_b.sh");
  } 
  else
  {
    int cnt = 0;
    printf("\npid:%d\n",pid);
    while (cnt++ < 20)
    {
      printf("zz\n");
      sleep(1);
      
    }
    /**
    char cmd[50];
    std::sprintf(cmd, "kill -2 %d", pid);
    system(cmd);
    printf(cmd);
    **/

    //KEY PART
    //killpg(pid,15);
    kill(pid,15);
    //system("roslaunch ros_play play.launch");
  }


  return 0;
}
#include <stdlib.h>
#include <unistd.h>
#include <iostream>


using namespace std;

int j = 0;

/*
*
*/
int main(int argc, char** argv) {

  signal(SIGCHLD,SIG_IGN); //avoid zombie process
  int *i;
  i = &j;

  int k=0;
  pid_t pid,pid1,pid2;
  cout < <"this is at beginning, pointer i is" < <i < <endl;

  sleep(1);
  pid = fork();
  if(pid <0)
  {
  cout < <"create childprocess error!" < <endl;
  }
  else if (pid == 0)
  {

  cout < <"for childprocess,pointer i = " < <i < <endl;
  for(k;k <10;k++)
  {
  (*i)++;
  cout < <"for childprocess,j = " < <*i < <endl;
  }


  }
  else if(pid > 0)
  {
  sleep(5);
  cout < <"for fatherprocess, j = " < <*i < <endl;
  cout < <"for fatherprocess, i = " < <i < <endl;

  }


  return (EXIT_SUCCESS);
} 

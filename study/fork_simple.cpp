#include <unistd.h>
#include <stdio.h>
#include <iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  /* code */
  char *p[] = {"abc", "a", "asdfgh cc"};
  printf("pid=%d\n", getpid());
  printf("ppid=%d\n", getppid());
  printf("size=%d\n",sizeof(p));
  return 0;
}

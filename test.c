#include <stdio.h>
#include <string.h> 
int main(void) // 标准 ! 
{
char x[10],i,*sp="asdfghj";
//scanf("%s",x);
for(i=0;*sp;i++) //*sp!='\0' *sp 循环结束条件
x[i]=*sp++;
printf("%s\n",x);
return 0;
}
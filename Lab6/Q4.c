#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void forkexample()
{
int a = 1;
if (fork() == 0)
printf("Child has value = %d\n", ++a);
else
printf("Parent has value = %d\n", --a);
}
int main()
{
forkexample();
return 0;
}
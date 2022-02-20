#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void forkexample()
{
if (fork()==0)
printf("Jod from Child!\n");
else
printf("Jod from Parent!\n");
}
int main()
{
forkexample();
return 0;
}
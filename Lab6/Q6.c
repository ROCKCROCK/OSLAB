#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
int i;
printf("hello before fork \n");
printf("i : %d\n",i);
i=fork();
printf("\n");
if(i==0)
{
printf("Child begins\n\n");
printf("child printing first time \n");
printf("getpid -> %d \t getppid -> %d \n",getpid(),getppid());
sleep(5);
printf("\nchild printing second time \n");
printf("getpid -> %d \t getppid -> %d \n",getpid(),getppid());
} else
{
printf("parent begins\n");
printf("getpid -> %d \t getppid -> %d \n",getpid(),getppid());
printf("\n");
}
printf("Hi after fork i -> %d\n",i);
return 0;
}
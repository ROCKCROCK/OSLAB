# include <stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
 #include <sys/wait.h>
int process_fork(int newproc)
{
	int i;
	for(i=1;i<newproc;i++)
	{
		if(fork()==0)
			return i;
	}
	return 0;
}

int process_join(int newproc,int id)
{
	int i;
	if(id==0)
	{
		for(i=1;i<newproc;i++)
		{
			wait(0);
			}
	}
	else
		exit(0);
}
int main()
{
int a[10]={1,2,3,4,5,6,7,8,9,10};
int sum1=0,sum2=0,sum=0;
int id,i;
id=process_fork(2);
if(id==0)
{
for(i=0;i<10;i=i+2)
{
sum1=sum1 + a[i];
}
printf("Parent Sum -> %d\n",sum1);
} else
{
for(i=1;i<10;i=i+2)
{
sum2=sum2 + a[i];
}
printf("Child Sum -> %d\n",sum2);
}
process_join(2,id);

sum=sum1 + sum2;
printf("Final Sum is -> %d\n", sum);
return 0;
}
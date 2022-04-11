#include<stdio.h>
int main()
{
int N1538Max[10][10], N1538need[10][10], N1538alloc[10][10], N1538avail[10], N1538completed[10], N1538safeSequence[10];
int N1538_p, N1538_r, N1538_i, N1538_j, N1538_process, N1538_count;
N1538_count = 0;

printf("Enter the no of processes : ");
scanf("%d", &N1538_p);

for(N1538_i = 0; N1538_i< N1538_p; N1538_i++)
	N1538completed[N1538_i] = 0;

printf("\n\nEnter the no of resources : ");
scanf("%d", &N1538_r);

printf("\n\nEnter the Max Matrix for each process : ");
for(N1538_i = 0; N1538_i < N1538_p; N1538_i++)
{
	printf("\nFor process %d : ", N1538_i + 1);
	for(N1538_j = 0; N1538_j < N1538_r; N1538_j++)
		scanf("%d", &N1538Max[N1538_i][N1538_j]);
}

printf("\n\nEnter the allocation for each process : ");
for(N1538_i = 0; N1538_i < N1538_p; N1538_i++)
{
	printf("\nFor process %d : ",N1538_i + 1);
	for(N1538_j = 0; N1538_j < N1538_r; N1538_j++)
		scanf("%d", &N1538alloc[N1538_i][N1538_j]);	
}

printf("\n\nEnter the Available Resources : ");
for(N1538_i = 0; N1538_i < N1538_r; N1538_i++)
		scanf("%d", &N1538avail[N1538_i]);	


	for(N1538_i = 0; N1538_i < N1538_p; N1538_i++)
		for(N1538_j = 0; N1538_j < N1538_r; N1538_j++)
			N1538need[N1538_i][N1538_j] = N1538Max[N1538_i][N1538_j] - N1538alloc[N1538_i][N1538_j];
		
do
{
	printf("\n Max matrix:\tAllocation matrix:\tNeed matrix:\n");
	for(N1538_i = 0; N1538_i < N1538_p; N1538_i++)
	{
		for( N1538_j = 0; N1538_j < N1538_r; N1538_j++)
			printf("%d  ", N1538Max[N1538_i][N1538_j]);
		printf("\t\t");
		for( N1538_j = 0; N1538_j < N1538_r; N1538_j++)
			printf("%d  ", N1538alloc[N1538_i][N1538_j]);
		printf("\t\t");
		for( N1538_j = 0; N1538_j < N1538_r; N1538_j++)
			printf("%d  ", N1538need[N1538_i][N1538_j]);
		printf("\n");
	}

	N1538_process = -1;

	for(N1538_i = 0; N1538_i < N1538_p; N1538_i++)
	{
		if(N1538completed[N1538_i] == 0)//if not completed
		{
			N1538_process = N1538_i ;
			for(N1538_j = 0; N1538_j < N1538_r; N1538_j++)
			{
				if(N1538avail[N1538_j] < N1538need[N1538_i][N1538_j])
				{
					N1538_process = -1;
					break;
				}
			}
		}
		if(N1538_process != -1)
			break;
	}

	if(N1538_process != -1)
	{
		printf("\nProcess %d runs to completion!", N1538_process + 1);
		N1538safeSequence[N1538_count] = N1538_process + 1;
		N1538_count++;
		for(N1538_j = 0; N1538_j < N1538_r; N1538_j++)
		{
			N1538avail[N1538_j] += N1538alloc[N1538_process][N1538_j];
			N1538alloc[N1538_process][N1538_j] = 0;
			N1538Max[N1538_process][N1538_j] = 0;
			N1538completed[N1538_process] = 1;
		}
	}
}while(N1538_count != N1538_p && N1538_process != -1);

if(N1538_count == N1538_p)
{
	printf("\nThe system is in a safe state!!\n");
	printf("Safe Sequence : < ");
	for( N1538_i = 0; N1538_i < N1538_p; N1538_i++)
			printf("P%d  ", N1538safeSequence[N1538_i]);
	printf(">\n");
}
else
	printf("\nThe system is in an unsafe state!!");
}
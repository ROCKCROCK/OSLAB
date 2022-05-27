#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat, rt, st;
    int remain_bt;
} p[100];

int findmax(int a, int b)
{
    if( a > b )
    {
     return a;
     }
     else
     {
     return b;
     }
}

int cpid(const void *a, const void *b)
{
    int x = ((struct process *)a)->pid;
    int y = ((struct process *)b)->pid;
    if (x < y)
        return -1;
    else if (x >= y)
        return 1;
}

int cat(const void *a, const void *b)
{
    int x = ((struct process *)a)->at;
    int y = ((struct process *)b)->at;
    if (x < y)
        return -1;
    else if (x >= y)
        return 1;
}
int main()
{

    int n, id;
    

    bool visit[100] = {false}, first_process = true;
    int current_time = 0;
    int completed = 0, tq, total_idle_time = 0;
    printf("Enter total number of processes: ");
    scanf("%d", &n);
    int queue[100], front = -1, rear = -1;
    float sum_tat = 0, sum_wt = 0, sum_rt = 0;

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process %d Arrival Time: ", i);
        scanf("%d", &p[i].at);
        p[i].pid = i;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process %d Burst Time: ", i);
        scanf("%d", &p[i].bt);
        p[i].remain_bt = p[i].bt;
    }

    printf("\nEnter time quanta: ");
    scanf("%d", &tq);

    qsort((void *)p, n, sizeof(struct process), cat);

    front = rear = 0;
    queue[rear] = 0;
    visit[0] = true;

    while (completed != n)
    {
        id = queue[front];

        front++;

        if (p[id].remain_bt == p[id].bt)
        {
            p[id].st = findmax(current_time, p[id].at);
            total_idle_time += (first_process == true) ? 0 : p[id].st - current_time;
            current_time = p[id].st;
            first_process = false;
        }

        if (p[id].remain_bt - tq > 0)
        {
            p[id].remain_bt -= tq;
            current_time += tq;
        }
        else
        {
            current_time += p[id].remain_bt;
            p[id].remain_bt = 0;
            completed++;

            p[id].ct = current_time;
            p[id].tat = p[id].ct - p[id].at;
            p[id].wt = p[id].tat - p[id].bt;
            p[id].rt = p[id].st - p[id].at;

            sum_tat += p[id].tat;
            sum_wt += p[id].wt;
            sum_rt += p[id].rt;
        }

        for (int i = 1; i < n; i++)
        {
            if (p[i].remain_bt > 0 && p[i].at <= current_time && visit[i] == false)
            {

                queue[++rear] = i;
                visit[i] = true;
            }
        }

        if (p[id].remain_bt > 0)

            queue[++rear] = id;

        if (front > rear)
        {
            for (int i = 1; i < n; i++)
            {
                if (p[i].remain_bt > 0)
                {
                    queue[rear++] = i;
                    visit[i] = true;
                    break;
                }
            }
        }
    }

    qsort((void *)p, n, sizeof(struct process), cpid);
    
    printf("\n---------------------------------------------------------------------------------------\n");
    printf("Process No.\tAT\tCPU Burst Time\tStart Time\tCT\tTAT\tWT\tRT\n");
    printf("\n---------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    printf("P%d\t\t%d\t%d\t\t%d\t\t%d\t%d\t%d\t%d\n", i, p[i].at, p[i].bt, p[i].st, p[i].ct, p[i].tat, p[i].wt, p[i].rt);
    printf("----------------------------------------------------------------------------------------\n");
    printf("Average Turn Around time= %.2f", (float)sum_tat / n);
    printf("\nAverage Waiting Time= %.2f", (float)sum_wt / n);
    printf("\nAverage Response Time= %.2f", (float)sum_rt / n);
    printf("\n---------------------------------------------------------------------------------------\n");
    return 0;
}
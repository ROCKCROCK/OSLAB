#include <stdio.h>
#include <stdlib.h>

struct process_struct
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat, rt, st;
} a[10]; 


int m(int a, int b)
{
    if(a>b)
    {
    return a;
    }
    else
    {
    return b;
    }
}

int main()
{
    int n;
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    float stat = 0, swt = 0;

    for (int i = 0; i < n; i++)
    {
        printf("Enter Process %d Arrival Time: ", i);
        scanf("%d", &a[i].at);
        a[i].pid = i;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process %d Burst Time: ", i);
        scanf("%d", &a[i].bt);
    }

    for (int i = 0; i < n; i++)
    {
        a[i].st = (i == 0) ? a[i].at : m(a[i].at, a[i - 1].ct);
        a[i].ct = a[i].st + a[i].bt;
        a[i].tat = a[i].ct - a[i].at;
        a[i].wt = a[i].tat - a[i].bt;

        stat = stat + a[i].tat;
        swt = swt + a[i].wt;
    }
    //sorting pid
       for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1-i); j++)
        {
            if (a[j].pid > a[j + 1].pid)
            {
                int temp = a[j].pid;
                a[j].pid = a[j + 1].pid;
                a[j + 1].pid = temp;
            } 
        }
    }
    //sorting arival time
       for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - 1-i); j++)
        {
            if (a[j].at > a[j + 1].at)
            {
                int temp = a[j].at;
                a[j].at = a[j + 1].at;
                a[j + 1].at = temp;
            } 
        }
    }
    //sorting burst time
       for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n-1-i); j++)
        {
            if (a[j].bt > a[j + 1].bt)
            {
                int temp = a[j].bt;
                a[j].bt = a[j + 1].bt;
                a[j + 1].bt = temp;
            } 
        }
    }
    printf("\n Process No. \tAT\tBurst Time\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t%d\t\t%d\t%d\t%d\n", a[i].pid, a[i].at, a[i].bt, a[i].ct, a[i].tat, a[i].wt);
        printf("\n");
    }
    printf("\nAverage Turn Around Time-> %f", stat / n);
    printf("\nAverage Waiting Time-> %f", swt / n);
    return 0;
}
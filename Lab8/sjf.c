#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
struct process
{
    int pid;
    int at;
    int bt;
    int ct, wt, tat, rt, st;
    float stat,swt,srt;
} c[20],d;
int findmax(int a, int b)
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
void enter(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process %d Arrival Time: ", i);
        scanf("%d", &c[i].at);
        c[i].pid = i;
    }

    for (int i = 0; i < n; i++)
    {
        printf("\nEnter Process %d Burst Time: ", i);
        scanf("%d", &c[i].bt);
    }
}
void processing(int n)
{
bool iscomp[100] = {false}, isfpro = true;
int ct = 0;
int comp = 0;
 d.stat=0; 
 d.swt = 0; 
 d.srt = 0; 
int tit = 0, prev = 0;
while (comp != n)
    {
        int minin = -1;
        int min = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (c[i].at <= ct && iscomp[i] == false)
            {
                if (c[i].bt < min)
                {
                    min = c[i].bt;
                    minin = i;
                }
                if (c[i].bt == min)
                {
                    if (c[i].at < c[minin].at)
                    {
                        min = c[i].bt;
                        minin = i;
                    }
                }
            }
        }

        if (minin == -1)
        {
            ct++;
        }
        else
        {
            c[minin].st = ct;
            c[minin].ct = c[minin].st + c[minin].bt;
            c[minin].tat = c[minin].ct - c[minin].at;
            c[minin].wt = c[minin].tat - c[minin].bt;
            c[minin].rt = c[minin].wt;

            d.stat += c[minin].tat;
            d.swt += c[minin].wt;
            d.srt += c[minin].rt;
            tit += (isfpro == true) ? 0 : (c[minin].st - prev);

            comp++;
            iscomp[minin] = true;
            ct = c[minin].ct;
            prev = ct;
            isfpro = false;
        }
    }
}    
void output(int n)
{
printf("\nProcess No.\tAT\tCPU Burst Time\tCT\tTAT\tWT\tRT\n");
    for (int i = 0; i < n; i++)
        printf("%d\t\t%d\t\t%d\t%d\t%d\t%d\t%d\n", c[i].pid, c[i].at, c[i].bt, c[i].ct, c[i].tat, c[i].wt, c[i].rt);
    printf("\n");
    printf("\nAverage Turn Around time-> %f ", (float)d.stat / n);
    printf("\nAverage Waiting Time-> %f ", (float)d.swt / n);
    printf("\nAverage Response Time-> %f ", (float)d.srt / n);
}    
int main()
{

    int n;
    printf("Enter total number of processes-> ");
    scanf("%d", &n);
    enter(n);
    processing(n);
    output(n);
    return 0;
}

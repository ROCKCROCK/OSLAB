#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
struct process
{
    int pno;
    int at,bt;
    int et,tat,wt;
    int rt;
    bool comp;
} p[20];
void srtf(int n)
{
    int compd = 0, ctime = 0, min = INT_MAX;
    int minpos = 0;
    while (compd != n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= ctime && p[i].rt < min && p[i].rt > 0)
            {
                min = p[i].rt;
                minpos = i;
                p[i].comp = true;
            }
        }
        if (p[minpos].comp == false)
        {
            ctime++;
            continue;
        }
        p[minpos].rt--;
        min = p[minpos].rt;
        if (p[minpos].rt == 0)
        {
            min = INT_MAX;
            compd++;
            p[minpos].comp = false;
            p[minpos].et = ctime + 1;
            p[minpos].wt = p[minpos].et - p[minpos].bt - p[minpos].at;
        }
        ctime++;
    }
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].bt + p[i].wt;
    }
}
double awt( int n) 
{
    double avg=0.0;
    for (int i = 0; i < n ; i++ )
    {
       avg=avg+p[i].wt;
    }
    avg=avg/n;
    return avg;
} 
double atat( int n) 
{
    double avg=0.0;
    for (int i = 0; i < n ; i++ )
    {
       avg=avg+p[i].tat;
    }
    avg=avg/n;
    return avg;
}
void enter(int n)
{
 printf("Enter the details for each process -> \n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the details for process P%d ->\n",(i));
        p[i].pno=i;
        printf("Arrival Time -> ");
        scanf("%d",&p[i].at);
        printf("Burst Time -> ");
        scanf("%d",&p[i].bt);
        p[i].rt = p[i].bt;
    }
}
void display(int n)
{
    
    printf("-----------------------------------------------------------\n");
    printf("Process \t AT \t BT \t CT \t TAT \t WT\n");
    
    for (int i = 0; i < n; i++)      
    {
        printf("P%d \t\t %d \t %d \t %d \t %d \t %d\n",p[i].pno,p[i].at,p[i].bt,p[i].et,p[i].tat,p[i].wt);
        
    }
    printf("-----------------------------------------------------------\n");
    printf ("Average turn around time is -> %lf\n",atat(n));
    printf ("Average waiting time is -> %lf\n",awt(n));
    printf("-----------------------------------------------------------\n");
    
}
int main()
{
    printf("Enter the number of processes -> ");
    int n;
    scanf("%d",&n);
    enter(n);
    srtf(n);
    display(n);
    return 0;
}
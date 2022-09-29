#include<stdio.h>
#define N 3


int aq[N],bq[N],f1,r1,f2,r2;

f1=-1;
f2=-1;
r1=-1;
r2=-1;

void menu()
{
    printf("\nMenu Panel");
    printf("\n1 - Enque In QA");
    printf("\n2 - Enque In QB");
    printf("\n3 - Deque");
    printf("\n4 - Display");
    printf("\n5 - Exit");
}

void enquea()
{
    if(r1==N-1)
    {
        printf("\nFull!!");
    }
    else
    {
        if(f1==-1)
            f1=0;
        r1=r1+1;
        printf("\nEnter value to insert     ");
        scanf("%d",&aq[r1]);
    }
}

void enqueb()
{
    if(r2==N-1)
    {
        printf("\nFull!!");
    }
    else
    {
        if(f2==-1)
            f2=0;
        r2=r2+1;
        printf("\nEnter value to insert     ");
        scanf("%d",&bq[r2]);
    }
}

void disp()
{
    if(f1==-1&&f2==-1)
    {
        printf("\nEmpty!!");
    }
    else
    {
        printf("\nQA = ");
        
        for(int i=f1;i<=r1;i++)
        {
            printf("\t%d",aq[i]);
        }
        dispb:
        printf("\nQB = ");
        for(int i=f2;i<=r2;i++)
        {
            printf("\t%d",bq[i]);
        }
    }
}

void deque()
{
    if(f1==-1&&f2==-1)
    {
        printf("\nEmpty!!");
    }
    else
    {
        if(f1!=-1)
        {
            printf("\nDeleted value is from QA = %d",aq[f1]);
            if(f1==r1)
            f1=r1=-1;
            else
            f1=f1+1;
        }
        else
        {
            printf("\nDeleted value is from QB = %d",bq[f2]);
            if(f2==r2)
            f2=r2=-1;
            else
            f2=f2+1;
        }
    }
}

int main()
{
    int opt;
    do
    {
        menu();
        printf("\nSelect Menu Option        ");
        scanf("%d",&opt);

        switch(opt)
        {
            case 1:
            enquea();
            break;
            case 2:
            enqueb();
            break;
            case 3:
            deque();
            break;
            case 4:
            disp();
            break;
            case 5:
            break;
            default:
            printf("\nInvalid Menu option!!");
        }

    }while(opt!=5);
    return 0;
}
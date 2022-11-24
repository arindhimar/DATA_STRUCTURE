#include<stdio.h>
#include<stdlib.h>
#define size 3

int qa[3],qb[3],f1=-1,f2=-1,r1=-1,r2=-1;

void menu()
{
    printf("\n1 - Enque");
    printf("\n2 - Deque");
    printf("\n3 - Display");
    printf("\n4 - Exit");
}

void enque()
{
    int opt;
    printf("\n1 - QA");
    printf("\n2 - QB");
    printf("\nSelect Queue      ");
    scanf("%d",&opt);
    switch(opt)
    {
        case 1:
        if(r1==size-1)
        {
            printf("\nFull!!");
        }
        else
        {
            printf("\nEnter value   ");
            scanf("%d",&qa[++r1]);
            if(f1==-1)
            f1=0;
        }
        break;
        case 2:
        if(r2==size-1)
        {
            printf("\nFull!!");
        }
        else
        {
            printf("\nEnter value   ");
            scanf("%d",&qb[++r2]);
            if(f2==-1)
            f2=0;
        }
        break;
        default:
        printf("\nInvalid Menu Option!!");
    }
}

void deque()
{
    if(f2==-1&&f1==-1)
    {
        printf("\nBoth Queue Are Empty!");
    }
    else
    {
        if(f1!=-1)
        {
            printf("\nElement Dequed is %d",qa[f1]);
            if(f1==r1)
            f1=r1=-1;
            else
            f1++;
        }
        else
        {
            printf("\nElement Dequed is %d",qb[f2]);
            if(f2==r2)
            f2=r2=-1;
            else
            f2++;
        }
    }
}

void disp()
{
    printf("\nQA    :   ");
    if(f1==-1)
    {
        printf("\tEmpty!!");
    }
    else
    {
        for(int i=f1;i<=r1;i++)
        {
            printf("\t%d",qa[i]);
        }
    }

    printf("\nQB    :   ");
    if(f2==-1)
    {
        printf("\tEmpty!!");
    }
    else
    {
        for(int i=f2;i<=r2;i++)
        {
            printf("\t%d",qb[i]);
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
            enque();
            break;
            case 2:
            deque();
            break;
            case 3:
            disp();
            break;
            case 4:
            break;
        }
    }while(opt!=4);
    return 0;
}
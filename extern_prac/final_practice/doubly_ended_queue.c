/*
    Author  :   Arin Dhimar
    Date    :   25-11-2022
    Code    :   Implementation of Doubly_Ended_Queue(Input Restricted) using array
*/

#include<stdio.h>
#define size 3

int queue[size],f=-1,r=-1;

void menu()
{
    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - RDeque");
    printf("\n 4 - Display");
    printf("\n 5 - Exit");
}

void enque()
{
    if(r==size-1)
    {
        printf("\nFull!!");
    }
    else
    {
        printf("\nEnter value to enque      ");
        scanf("%d",&queue[++r]);
        if(f==-1)
        f=0;
    }
}

void deque()
{
    if(f==-1)
    {
        printf("\nEmpty!");
    }
    else
    {
        printf("\nElement popped is %d  ",queue[f]);
        if(f==r)
        f=r=-1;
        else
        f++;
    }
}

void rdeque()
{
    if(r==-1)
    {
        printf("\nEmpty!");
    }
    else
    {
        printf("\nElement popped is %d  ",queue[r]);
        if(f==r)
        f=r=-1;
        else
        r--;
    }
}

void disp()
{
    if(f==-1)
    {
        printf("\nEmpty!!");
    }
    else
    {
        printf("\nQueue :   ");
        for(int i=f;i<=r;i++)
        {
            printf("\t%d",queue[i]);
        }
    }
}

int main()
{
    int opt;
    do
    {
        menu();
        printf("\nEnter Menu Option     ");
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
            rdeque();
            break;
            case 4:
            disp();
            break;
            case 5:
            break;
        }
    }while(opt!=5);
}
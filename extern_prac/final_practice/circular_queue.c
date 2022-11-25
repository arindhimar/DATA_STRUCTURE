/*
    Author  :   Arin Dhimar
    Date    :   25-11-2022
    Code    :   Implementation of Circular_Queue using array
*/

#include<stdio.h>
#define size 3
void menu()
{
    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
}

int cq[size],f=-1,r=-1;

void enque()
{
    if((r+1)%size==f)
    {
        printf("\nFull!!");
    }
    else
    {
        int temp;
        printf("\nEnter Value       ");
        scanf("%d",&temp);
        r=(r+1)%size;
        cq[r]=temp;
        if(f==-1)
        f=0;
    }
}

void deque()
{
    if(f==-1)
    {
        printf("\nEMpty!!");
    }
    else
    {
        printf("\nElement Dequed is %d",cq[f]);
        if(f==r)
        f=r=-1;
        else
        f=(f+1)%size;
    }
}

void disp()
{
    if(f==-1)
    printf("\nEmpty!!");
    else
    {
        printf("\nQueue    :   ");
        if(f<=r)
        {
            for(int i=f;i<=r;i++)
            {
                printf("\t%d",cq[i]);
            }
        }
        else
        {
            for(int i=0;i<=r;i++)
            {
                printf("\t%d",cq[i]);
            }
            for(int i=f;i<size;i++)
            {
                printf("\t%d",cq[i]);
            }
        }
    }
}


int main()
{
    int opt;
    do{
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
}

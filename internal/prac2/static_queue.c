#include<stdio.h>
#include<stdlib.h>
#define N 3

int queue[N],f,r;

f=-1;
r=-1;
void menu()
{
    printf("\nMenu Panel");
    printf("\n1 - Enque");
    printf("\n2 - Deque");
    printf("\n3 - Display");
    printf("\n4 - Exit");
}

void enque()
{
    if(r==N-1)
    {
        printf("\nQueue is full!!");
    }
    else
    {
        printf("\nEnter value to insert         ");
        scanf("%d",&queue[++r]);
        if(f==-1)
        {
            f=0;
        }

    }
}

void deque()
{
    if(f==-1&&r==-1)
    {
        printf("\nQueue is Empty!!");
    }
    else
    {
        if(f==r)
        {
            printf("\nDequed Element is %d",queue[r]);
            f=r=-1;
        }
        else
        {
            printf("\nDequed Element is %d",queue[f++]);
        }
    }
}

void disp()
{
    if(f==-1&&r==-1)
    {
        printf("\nEmptyy!!");
    }
    else
    {
        printf("\nQueue : ");
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
            exit(0);
            default:
            printf("\nInvalid Menu Option!!");
        }


    }while(opt!=4);
    
    return 0;
}
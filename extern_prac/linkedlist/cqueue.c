#include<stdio.h>
#include<stdlib.h>
#define size 4

int queue[size],f=-1,r=-1;

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
    if((r+1)%size==f)
    {
        printf("\nFull!!");
    }
    else
    {
        int temp;
        printf("\nEnter value to enque      ");
        scanf("%d",&temp);
        if(f==-1 && r==-1)
        {
            r=(r+1)%size;
            queue[r]=temp;
            f=0;
        }
        else
        {
            r=(r+1)%size;
            queue[r]=temp;
        }
    }
}

void deque()
{
    if(f==-1&&r==-1)
    {
        printf("\nEmpty!");
    }
    else
    {
        if(f==r)
        {
            printf("\nDequed Element is %d",queue[f]);
            f=r=-1;
        }
        else
        {
            printf("\nDequed Element is %d",queue[f]);
            f=(f+1)%size;
        }
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
        printf("\nQueue:");
        if(f<r)
        {
            for(int i=f;i<=r;i++)
            {
                printf("\t%d",queue[i]);
            }
        }
        else
        {
            for(int i=0;i<=r;i++)
            {
                printf("\t%d",queue[i]);
            }
            for(int i=f;i<size;i++)
            {
                printf("\t%d",queue[i]);
            }
        }
    }
}

int main()
{
    //printf("\nHello!!");
    int opt;
    do
    {
        menu();
        printf("\nSelect Menu Option    ");
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
}
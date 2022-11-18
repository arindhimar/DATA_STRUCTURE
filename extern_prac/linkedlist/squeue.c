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
    if(r==size-1)
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
            queue[++r]=temp;
            f++;
        }
        else
        {
            queue[++r]=temp;
        }
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
        if(f==r)
        {
            printf("Element Dequed is %d",queue[f]);
            f=r=-1;
        }
        else
        {
            printf("Element Dequed is %d",queue[f]);
            f++;
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
        for(int i=f;i<=r;i++)
        {
            printf("\t%d",queue[i]);
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
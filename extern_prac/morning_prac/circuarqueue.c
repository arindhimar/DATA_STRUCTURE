#include<stdio.h>
#include<stdlib.h>
#define size 3

int queue[size],r=-1,f=-1;

void menu()
{
    printf("\n1 - Enque");
    printf("\n2 - Deque");
    printf("\n3 - Display");
    printf("\n4 - Exit");
}

void enque()
{
    if((r+1)%size==f)
    {
        printf("\nFULL!!");
    }
    else
    {
        r=(r+1)%size;
        printf("\nEnter Value       ");
        scanf("%d",&queue[r]);
        if(f==-1)
        f=0;
    }
}

void deque()
{
    if(r==-1)
    {
        printf("\nEmpty!!");
    }
    else
    {
        printf("\nDequed Value is %d",queue[f]);
        if(f==r)
        {
            f=r=-1;
        }
        else
        f=(f+1)%size;
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
        if(f<=r)
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
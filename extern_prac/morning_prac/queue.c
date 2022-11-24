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
    if(r==size-1)
    {
        printf("\nFull!!");
    }
    else
    {
        printf("\nEnter Value       ");
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
        printf("\nDequed Value is %d",queue[f]);
        if(f==r)
        f=r=-1;
        else
        f++;
    }
}


void disp()
{
    if(f==-1)
    {
        printf("\nEmpty!");
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
    do{
        menu();
        printf("\nSelect Menu option        ");
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
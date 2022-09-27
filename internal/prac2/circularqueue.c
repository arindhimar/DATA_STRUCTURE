#include<stdio.h>
#include<stdlib.h>
#define N 3


int queue[N],r,f;
f=-1;
r=-1;
void menu()
{
    printf("\nMenu Panel");
    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
}

void enque()
{
    if((r+1)%N==f)
    {
        printf("\nQueue is full!!");
    }
    else
    {
        r=(r+1)%N;
        printf("\nEnter Element to insert       ");
        scanf("%d",&queue[r]);
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
            printf("\nElement dequed is %d",queue[r]);
            f=r=-1;
        }
        else
        {
            printf("\nElement Dequed is %d",queue[f]);
            f=(f+1)%N;
        }



    }
}

void disp()
{
    if(f==-1&&r==-1)
    {
        printf("\nEmpty!!");
    }
    else
    {
        printf("\nQueue : ");
        if(f<r)
        {
            for(int i=f;i<=r;i++)
            {
                printf("\t%d",queue[i]);
            }
        }
        else
        {

            for(int j=0;j<=r;j++)
            {
                 printf("\t%d",queue[j]);
            }
            for(int i=f;i<N;i++)
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
            exit(0);
            default:
            printf("\nInvalid Menu option!!");
        }


    }while(opt!=4);

    return 0;
}
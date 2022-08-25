#include<stdio.h>
#define N 4

int queue[N],rear=-1,front=-1,value;

void enque()
{
    if(rear==N-1)
    {
        printf("\nQUEUE IS FULL!!");
    }
    else
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&value);
        if(rear==-1)
        {
            queue[++rear]=value;
            front++;
        }
        else
        {
            queue[++rear]=value;
        }
    }
}



void fdeque()
{
    if(front==-1&&rear==-1)
    {
        printf("\nQUEUE IS EMPTY!!");
    }
    else
    {
        if(front==rear)
        {
            printf("\nDEQUED ELEMENT IS %d",queue[front]);
            front=-1;
            rear=-1;
        }
        else
        {
            printf("\nDEQUED ELEMENT IS %d",queue[front]);
            front++;
        }
    }
}


void rdeque()
{
    if(front==-1&&rear==-1)
    {
        printf("\nQUEUE IS EMPTY!!");
    }
    else
    {
        if(front==rear)
        {
            printf("\nDEQUED ELEMENT IS %d",queue[rear]);
            front=-1;
            rear=-1;
        }
        else
        {
            printf("\nDEQUED ELEMENT IS %d",queue[rear]);
            rear--;
        }
    }
}

void disp()
{
    int i;
    if(front==-1&&rear==-1)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\t%d",queue[i]);
        }
    }
}

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n1 - ENQUE");
    printf("\n2 - FDEQUE");
    printf("\n3 - RDEQUE");
    printf("\n4 - DISPLAY");
    printf("\n5 - EXIT");
}

int main()
{
    int opt;

    do
    {
        menu();
        printf("\nSELECT MENU OPTION        ");
        scanf("%d",&opt);

        switch(opt)
        {
            case 1:
            enque();
            break;
            case 2:
            fdeque();
            break;
            case 3:
            rdeque();
            break;
            case 4:
            disp();
            break;
            case 5:
            exit(0);
            default:
                printf("\nINVALID MENU OPTION");
        }

    }while(opt!=5);

}

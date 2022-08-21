#include<stdio.h>

#define N 4

int queue[N];
int front=-1,rear=-1;

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n1 - RENQUE");
    printf("\n2 - FDEQUE");
    printf("\n3 - FENQUE");
    printf("\n4 - RDEQUE");
    printf("\n5 - DISP");
    printf("\n6 - EXIT");
}

void renque()
{
    int n;
    if(rear==N-1)
    {
        printf("\nQUEUE IS FULL!!");
    }
    else
    {
        printf("\nENTER VALUE TO ENQUE      ");
        scanf("%d",&n);

        if(rear==-1)
        {
            queue[++rear]=n;
            front++;
        }
        else
        {
            queue[++rear]=n;
        }
    }
}



void rdeque()
{
    if(rear==front)
    {
        printf("\nELEMENT DEQUED IS %d",queue[front]);
        printf("\nQUEUE RESET!!");
        rear=-1;
        front=-1;
    }
    else
    {
        printf("\nELEMENT DEQUED IS %d",queue[rear]);
        rear--;
    }
}


void fenque()
{
    int n;
    if(front==N-1)
    {
        printf("\nQUEUE IS FULL!!");
    }
    else
    {
        printf("\nENTER VALUE TO ENQUE      ");
        scanf("%d",&n);

        if(front==-1)
        {
            queue[front++]=n;
            rear++;
        }
        else
        {
            queue[--front]=n;
        }
    }
}



void fdeque()
{
    if(front==N)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else if(rear==front)
    {
        printf("\nELEMENT DEQUED IS %d",queue[front]);
        printf("\nQUEUE RESET!!");
        rear=-1;
        front=-1;
    }
    else
    {
        printf("\nELEMENT DEQUED IS %d",queue[front]);
        front++;
    }
}


void disp()
{
    int i;
    if(rear==-1)
    {
        printf("\nQUEUE IS EMPTY!!");
    }
    else
    {
        for(i=front;i<=rear;i++)
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
        printf("\nSELECT MENU OPTION    ===>>>      ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                renque();
                break;
            case 2:
                fdeque();
                break;
            case 3:
                fenque();
                break;
            case 4:
                rdeque();
                break;
            case 5:
                disp();
                break;
            default:
                break;
        }

    }while(opt!=6);

    return 0;
}


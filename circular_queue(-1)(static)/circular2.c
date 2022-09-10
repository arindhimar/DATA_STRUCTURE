
#include<stdio.h>

#define N 4

int queue[N];
int front=-1,rear=-1;

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n1 - ENQUE");
    printf("\n2 - DEQUE");
    printf("\n3 - DISP");
    printf("\n4 - EXIT");
}

void enque()
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



void deque()
{
    int i;
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
        for(i=1;i<=rear;i++)
        {
            queue[i-1]=queue[i];
        }
        rear--;
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
        for(i=0;i<=rear;i++)
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
                enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                disp();
                break;
            default:
                break;
        }

    }while(opt!=4);

    return 0;
}

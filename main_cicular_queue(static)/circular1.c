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
    if((rear+1)%N==front)
    {
        printf("\nQUEUE IS FULL!!");
    }
    else
    {
        printf("\nENTER VALUE TO ENQUE      ");
        scanf("%d",&n);
        if(rear==-1)
        {
            rear=(rear+1)%N;
            queue[rear]=n;
            front++;
        }
        else
        {
            rear=(rear+1)%N;
            queue[rear]=n;
            printf("%d",rear);
        }
    }
}


void deque()
{
    if(rear==front)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else
    {
        printf("\nELEMENT DEQUED IS %d",queue[front]);
        front=(front+1)%N;
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
        for(i=0;i<N;i++)
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

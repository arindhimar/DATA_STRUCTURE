#include<stdio.h>

#define N 4

int queue[N];
int front=0,rear=0;

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
    if(rear==N)
    {
        printf("\nQUEUE IS FULL!!");
    }
    else
    {
        printf("\nENTER VALUE TO ENQUE      ");
        scanf("%d",&n);

        if(rear==0)
        {
            queue[rear++]=n;
            front++;
        }
        else
        {
            queue[rear++]=n;
        }
    }
}



void deque()
{
    if(front==N+1)
    {
        printf("\nQUEUE IS EMPTY");
    }
    else if(rear==front)
    {
        printf("\nELEMENT DEQUED IS %d",queue[front]);
        printf("\nQUEUE RESET!!");
        rear=0;
        front=0;
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
    if(rear==0)
    {
        printf("\nQUEUE IS EMPTY!!");
    }
    else
    {
        for(i=front-1;i<rear;i++)
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

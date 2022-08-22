#include<stdio.h>
#define N 4
int  queue[N];
int front=-1;
int  rear=-1;

void menu()
{
	printf("\n ******** MENU ********");
	printf("\n 1-enque");
	printf("\n 2-deque");
	printf("\n 3-display");
	printf("\n 4-exit");
}

void enque(int x)
{
    if ((rear+1)%N==front)
    {
        printf("Queue is overflow..");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear=(rear+1)%N;
        queue[rear] = x;
    }
}
void deque()
{
	if(front==-1 && rear==-1)
	{
		printf("queue is Empty");
	}
	else if(front==rear)
	{
		printf("%d",queue[front]);
		front=-1;
		rear=-1;
	}
	else
	{
		printf("%d",queue[front]);
		front=(front+1)%N;
	}
}

void display()
{
	int i;
	if(front==-1 && rear==-1)
	{
		printf("queue is Empty");
	}
	else
	{
		printf("queue is:");
		if(rear<front)
        {
            for(i=0;i<=rear;i++)
            {
                printf("\t%d",queue[i]);
            }
            for(i=front;i<N;i++)
            {
                printf("\t%d",queue[i]);
            }
        }
        else
        {
            for(i=front;i<=rear;i++)
            {
                printf("\t%d",queue[i]);
            }
        }
	}
}
int main()
{
	int a,val;
	do
	{
		menu();
		printf("\n select opition*********");
		scanf("%d",&a);
		switch(a)
		{
			case 1:
			    printf("\nENTER VALUE TO INSERT ");
			    scanf("%d",&val);
				enque(val);
				break;
			case 2:
				deque();
				break;
			case 3:
				display();
				break;
			default:
				break;
		}
	}while(a!=4);
	return 0;

}

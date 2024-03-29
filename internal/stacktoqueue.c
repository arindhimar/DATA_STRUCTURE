#include<stdio.h>
#include<stdlib.h>
#define N 4
#define S 3

char stack[N],queue[S];
int pos=-1,front=-1,rear=-1;



void menu()
{
    printf("\nMenu Panel");
    printf("\n 1 - PUSH");
    printf("\n 2 - POP");
    printf("\n 3 - DISPLAY");
    printf("\n 4 - EXIT");
}

void push()
{
    char ch[1];
    if(pos==N-1)
    {
        printf("\nStack is Full!!");
        return;
    }
    printf("\nEnter char to push    ");
    scanf("%s",ch);
    stack[++pos]=ch[0];
}

void pop()
{
    if((rear+1)%S==front)
    {
        printf("\nQueue is Full!!");
        printf("\nChar not popped!!");
        return;
    }
    if(pos==-1)
    {
        printf("\nStack is Empty!!");
        return;
    }
    if(front==-1&&rear==-1)
    {
        printf("\nChar popped to Queue is %c",stack[pos]);
        front=rear=0;
        queue[rear]=stack[pos--];
    }
    else
    {
        printf("\nChar popped to Queue is %c",stack[pos]);
        rear=(rear+1)%N;
        queue[rear]=stack[pos--];
    }
}

void disp()
{
    if(pos==-1&&rear==-1)
    {
        printf(("\nEmpty!!"));
        return;
    }
    printf("\nStack : ");
    for(int i=0;i<=pos;i++)
    {
        printf("\t%c",stack[i]);
    }
    printf("\nQueue : ");
    for(int i=front;i<=rear;i++)
    {
        printf("\t%c",queue[i]);
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
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            disp();
            break;
            case 4:
            exit(0);
            default:
            printf("\nINvalid Menu Option");
        }
    }while (opt!=4);

    return 0;
}
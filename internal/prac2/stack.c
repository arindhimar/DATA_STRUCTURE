#include<stdio.h>
#include<stdlib.h>
#define N 3
int top=-1;
char stack[N];

void menu()
{
    printf("\nMenu Panel");
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
}

void push()
{
    if(top==N-1)
    {
        printf("\nStack is full!!");
    }
    else
    {
        printf("\nEnter element to insert       ");
        scanf("%s",&stack[++top]);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nStack is Empty!!");
    }
    else
    {
        printf("\nElement popped is %c",stack[top--]);
    }
}

void disp()
{
    if(top==-1)
    {
        printf("\nStack is empty!!");
    }
    else
    {
        printf("\nStack : ");
        for(int i=0;i<=top;i++)
        {
            printf("\t%c",stack[i]);
        }
    }
}

int main()
{
    int opt;

    do
    {
        menu();
        printf("\nSelect menu option        ");
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
            printf("\nInvalid menu option!!");


        }
    }while(opt!=4);

    return 0;
}
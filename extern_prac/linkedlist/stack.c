#include<stdio.h>
#include<stdlib.h>
#define size 4

int top = -1 ;
int stack[size];

void menu()
{
    printf("\nMenu Panel");
    printf("\n1 - Push");
    printf("\n2 - Pop");
    printf("\n3 - Display");
    printf("\n4 - Exit");
}

void push()
{
    if(top==size-1)
    printf("\nFull!!");
    else
    {
        printf("\nEnter value to push       ");
        scanf("%d",&stack[++top]);
    }
}

void pop()
{
    if(top == -1)
    printf("\nEmpty!!");
    else
    {
        printf("\nElement poppped is %d",stack[top--]);
    }
}

void disp()
{
    if(top==-1)
    {
        printf("\nEmpty!!");
    }
    else
    {
        printf("\nStack : ");
        for(int i=0;i<=top;i++)
        {
            printf("\t%d",stack[i]);
        }
    }
}

int main()
{
    //printf("\nHello World!!");
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
            printf("\nInvalid Menu Option!!" );
        }
    }while(opt!=4);
    return 0;
}
/*
    Author  :   Arin Dhimar
    Date    :   25-11-2022
    Code    :   Implementation of Stack using array
*/

#include<stdio.h>
#define size 3
int stack[size],top=-1;
void menu()
{
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
}

void push()
{
    if(top==size-1)
    {
        printf("\nFull!!");
    }
    else
    {
        printf("\nEnter value to push       ");
        scanf("%d",&stack[++top]);
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nEmpty!!");
    }
    else
    {
        printf("\nElement Poppped is %d",stack[top--]);
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
        printf("\nStack :   ");
        for(int i=0;i<=top;i++)
        {
            printf("\t%d",stack[i]);
        }
    }
}

int main()
{
    int opt;
    do
    {
        menu();
        printf("\nEnter Menu Option     ");
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
            case 4:
            break;
        }
    }while(opt!=4);
}
#include<stdio.h>
#include<stdlib.h>
#define size 5

void menu()
{
    printf("\n 1 - Push");
    printf("\n 2 - Pop");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
}

int stack[size],top=-1;

void push()
{
    if(top==size-1)
    {
        printf("\nFull!!");
    }
    else
    {
        printf("\nEnter Value       ");
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
        printf("\nElement popped is %d",stack[top--]);
    }
}

void disp()
{
    if(top==-1)
    {
        printf("\nEmpty!");
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
            break;
        }

    }while(opt!=4);
    return 0;
}
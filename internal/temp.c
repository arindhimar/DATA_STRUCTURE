#include<stdio.h>
#define N 3

char stack[N];
int top=-1;

void menu()
{
    printf("\nMenu Panel");
    printf("\n1 - Push");
    printf("\n2 - Pop");
    printf("\n3 - Diplay");
    printf("\n4 - Exit");
}

void push()
{
    if(top==N-1)
    {
        printf("\nFull!!");
    }
    else
    {
        top=top+1;
        printf("\nEnter Value to Push       ");
        scanf("%s",&stack[top]);
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
        printf("\nDeleted Element is %c",stack[top]);
        top=top-1;
    }
}

void disp()
{
    if(top==-1)
    {
        printf("\nStack is Empty!!");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("\t %c",stack[i]);
        }
    }
}

int main()
{
    int opt;
    do
    {
        menu();
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
            default:
            printf("\nInvalid Menu Option !!");
        }
    }while(opt!=4);
    return 0;
}
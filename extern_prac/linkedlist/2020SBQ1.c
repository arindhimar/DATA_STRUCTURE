#include<stdio.h>

char stack[4],queue[3];
int top=-1,f=-1,r=-1;

void menu()
{
    printf("\n1 - Push");
    printf("\n2 - Pop");
    printf("\n3 - Display");
    printf("\n4 - Exit");
}

void push()
{
    if(top==3)
    {
        printf("\nStack is FULL!!");
    }
    else
    {
        char temp[1];
        printf("\nEnter char to push        ");
        scanf("%s",&temp[0]);
        stack[++top]=temp[0];
    }
}

void pop()
{
    if(top==-1)
    {
        printf("\nStack is empty!!");
    }
    else if((r+1)%3==f)
    {
        printf("\nQueue is full!!");
    }
    else
    {
        printf("\nElement shifted to queue is %c",stack[top]);
        if(r==-1)
        {
            r=f=0;
            queue[f]=stack[top--];
        }
        else
        {
            r=(r+1)%3;
            queue[r]=stack[top--];
        }
    }
}

void disp()
{
    printf("\nStack :");
    if(top==-1)
    {
        printf("\tEmpty!!");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("\t%c",stack[i]);
        }
    }
    printf("\nQueue :");
    if(f==-1)
    {
        printf("\tEmpty!!");
    }
    else
    {
        for(int i=f;i<=r;i++)
        {
            printf("\t%c",queue[i]);
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
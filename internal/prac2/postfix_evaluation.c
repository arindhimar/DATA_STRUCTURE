#include<stdio.h>
#define N 20

int top=-1;

char postfix[N],stack[N],ch;

char pop()
{
    return stack[top--];
}

void push(char ch)
{
    stack[++top]=ch;
}

int main()
{
    printf("\nEnter postfix     ");
    scanf("%s",postfix);

    int i=0,j=0,t1,t2,t;

    while(postfix[i]!='\0')
    {
        ch=postfix[i];

        switch(ch)
        {
            case '+':
            t2=pop();
            t1=pop();
            t=t1+t2;
            push(t);
            break;

            case '-':
            t2=pop();
            t1=pop();
            t=t1-t2;
            push(t);
            break;

            case '*':
            t2=pop();
            t1=pop();
            t=t1*t2;
            push(t);
            break;

            case '/':
            t2=pop();
            t1=pop();
            t=t1/t2;
            push(t);
            break;

            default:
            printf("\nEnter value for %c",ch);
            scanf("%d",&t);
            push(t);

        }

        i=i+1;
    }

    printf("\nResult = %d",stack[0]);


    return 0;
}
#include<stdio.h>
#define size 10

int top=-1;
char postfix[size],stack[size];

void push(int n)
{
    stack[++top]=n;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char ch;
    printf("\nEnter postfix         ");
    scanf("%s",postfix);

    int i=0,res,t1,t2;

    while(postfix[i]!='\0')
    {
        ch=postfix[i];

        switch(ch)
        {
            case '+':
            t2=pop();
            t1=pop();
            res=t1+t2;
            push(res);
            break;

            case '-':
            t2=pop();
            t1=pop();
            res=t1-t2;
            push(res);
            break;
            

            case '*':
            t2=pop();
            t1=pop();
            res=t1*t2;
            push(res);
            break;

            case '/':
            t2=pop();
            t1=pop();
            res=t1/t2;
            push(res);
            break;
            

            default:
            printf("\nEnter value for '%c' ",postfix[i]);
            scanf("%d",&res);
            push(res);

        }

        i++;
    }
    printf("\nEvaluation : %d",stack[0]);
    return 0;
}
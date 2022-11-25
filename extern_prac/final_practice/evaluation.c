/*
    Author  :   Arin Dhimar
    Date    :   25-11-2022
    Code    :   Evaluation_Of_Postfix
*/

#include<stdio.h>

#define size 30

int stack[size];
char postfix[size];
int top=-1;

void push(int ch)
{
    stack[++top]=ch;
}

int pop()
{
    return stack[top--];
}

int main()
{

    printf("\nEnter Postfix     ");
    scanf("%s",postfix);

    int t2,t1,res,i=0;
    char ch;

    while(postfix[i]!='\0')
    {
        ch=postfix[i];

        switch(ch)
        {
            case'+':
            t2=pop();
            t1=pop();
            res=t1+t2;
            push(res);
            break;

            case'-':
            t2=pop();
            t1=pop();
            res=t1-t2;
            push(res);
            break;

            case'*':
            t2=pop();
            t1=pop();
            res=t1*t2;
            push(res);
            break; 

            case'/':
            t2=pop();
            t1=pop();
            res=t1+t2;
            push(res);
            break;           

            default:
            printf("\nEnter Value for %c        ",ch);
            scanf("%d",&res);
            push(res);
            break;
        }
        i=i+1;
    }

    printf("\nResult    :   %d",stack[top]);

    return 0;
}

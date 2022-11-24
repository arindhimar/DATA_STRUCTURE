#include<stdio.h>
#include<stdlib.h>
#define size 25

char stack[size],postfix[25];
int top=-1;

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
    printf("\nEnter postfic equation        ");
    scanf("%s",postfix);

    int i=0,t1,t2,res;

    char ch;

    
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
            printf("\nEnter value for %c   :   ",ch);
            scanf("%d",&res);
            push(res);

        }
        i=i+1;
    }

    printf("\nResult :  %d",stack[0]);

    return 0;
}
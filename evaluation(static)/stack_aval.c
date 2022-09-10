#include<stdio.h>
#define N 10
int top=-1;

char stack[N];

void push(char ch)
{
    if(top==N-1)
    {
        printf("\nSTACK OVERFLOW!!");
    }
    else
    {
        stack[++top]=ch;
    }
}

char pop()
{
    if(top==-1)
    {
        printf("\nSTACK IS EMPTY");
    }
    else
    {
        return(stack[top--]);
    }
}



int main()
{
    int t1,t2,result;
    char postfix[N],ch;
    printf("\nENTER POSTFIX EQUATION    ");
    scanf("%s",postfix);

    int i=0;

    while(postfix[i]!='\0')
    {
        ch=postfix[i];
        switch(ch)
        {
            case '+':
                t2=pop();
                t1=pop();
                result=t1+t2;
                push(result);
                break;
            case '-':
                t2=pop();
                t1=pop();
                result=t1-t2;
                push(result);
                break;
            case '*':
                t2=pop();
                t1=pop();
                result=t1*t2;
                push(result);
                break;
            case '/':
                t2=pop();
                t1=pop();
                result=t1/t2;
                push(result);
                break;
            default:
                printf("\nENTER VALUE FOR %c    ",ch);
                scanf("%d",&result);
                push(result);
                break;
        }
        i++;
    }
    printf("\nRESULT = %d",stack[0]);

    return 0;
}

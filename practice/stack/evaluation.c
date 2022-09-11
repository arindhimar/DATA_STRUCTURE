#include<stdio.h>
#define N 20

char postfix[N];

int stack[N];

int pos=-1;
int pop()
{
    if(pos==-1)
    {
        printf("\nSTACK IS EMPTY!!");
    }
    else
    {
        return stack[pos--];
    }
}

void push(int ch)
{
    if(pos==N-1)
    {
        printf(("\nFULL!!"));
    }
    else
    {
        stack[++pos]=ch;
    }
}

int main()
{
    printf("\nENTER postfix       ");
    scanf("%s",postfix);

    char ch,temp;
    int t1=01,t2=0,t=0;

    int i=0;

    ch=postfix[i];

    while (postfix[i]!='\0')
    {

        switch(ch)
        {
            case '+':
            printf("c1");
            t2=pop();
            t1=pop();
            t=t1+t2;
            push(t);
            break;

            case '-':
            printf("c2");
            t2=pop();
            t1=pop();
            t=t1-t2;
            push(t);
            break;
            
            case '*':
            printf("c3");
            t2=pop();
            t1=pop();
            t=t1*t2;
            push(t);
            break;

            case '/':
            printf("c4");
            t2=pop();
            t1=pop();
            t=t1/t2;
            push(t);
            break;

            default:
            printf("\nENTER VALUE FOR %c    ",ch);
            scanf("%d",&t);
            push(t);
            break;
        }
        i++;  
        ch=postfix[i];
    }

    printf("\nRESULT = %d",stack[0]);
    return 0;
}
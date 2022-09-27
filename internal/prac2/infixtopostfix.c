#include<stdio.h>
#define N 10

char infix[N],postfix[N],stack[N],ch;
int top=-1;

char pop()
{
    return stack[top--];
}

void push(char c)
{
    stack[++top]=c;
}

int main()
{
    printf("\nEnter infix equation      ");
    scanf("%s",infix);

    int i=0,j=0;

    char t;
    while(infix[i]!='\0')
    {
        ch=infix[i];

        switch(ch)
        {

            case '(':
            push(ch);
            break;
            
            case ')':
            t=pop();
            while(t!='(')
            {
                postfix[j++]=t;
                t=pop();
            }
            break;

            case '+':
            while(stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='/')
            {
                postfix[j++]=pop();
            }
            push(ch);
            break;

            case '-':
            while(stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='/')
            {
                postfix[j++]=pop();
            }
            push(ch);
            break;

            case '*':
            while(stack[top]=='*'||stack[top]=='/')
            {
                postfix[j++]=pop();
            }
            push(ch);
            break;
            
            case '/':
            while(stack[top]=='*'||stack[top]=='/')
            {
                postfix[j++]=pop();
            }
            push(ch);
            break;

            default:
            postfix[j++]=ch;


        }
        
        i=i+1;
    }

    while(top!=-1)
    {
        postfix[j++]=pop();
    }

    postfix[j]='\0';

    printf("\nPostfix = %s",postfix );

    return 0;
}
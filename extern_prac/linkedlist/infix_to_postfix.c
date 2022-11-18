#include<stdio.h>
#define size 10
int top=-1;

char postfix[size],infix[size],stack[size];

void push(char c)
{
    stack[++top]=c;
}

char pop()
{
    return stack[top--];
}

int main()
{
    printf("\nEnter infix equation          ");
    scanf("%s",infix);
    char ch,temp;
    int i=0,j=0;

    while(infix[i]!='\0')
    {
        ch=infix[i];

        switch(ch)
        {
            case '(':
            push(ch);
            break;

            case ')':
            temp=pop();
            while(temp!='(')
            {
                postfix[j++]=temp;
                temp=pop();
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

        i++;

    }

    while(top!=-1)
    {
        postfix[j++]=pop();
    }

    printf("\nPostfix : %s",postfix);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

char stack[25],postfix[25],infix[25];
int top=-1;
void push(char ch)
{
    stack[++top]=ch;
}

char pop()
{
    return stack[top--];
}

int main()
{
    printf("\nEnter infix equation      ");
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

        i=i+1;
    }
    while(top!=-1)
    {
        postfix[j++]=pop();
    }
    postfix[j++]='\0';

    printf("\nPostfix   :   %s",postfix);
    
    return 0;
}
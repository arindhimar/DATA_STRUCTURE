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
    char infix[N],postfix[N];

    printf("\nENTER EXPRESSION          ");
    scanf("%s",&infix);

    //printf("\n%s",infix);

    int i=0,j=0;

    char ch;

    while(infix[i]!='\0')
    {
        ch=infix[i];
        switch(ch)
        {
            case '+':
            while(stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='/')
            {
                //printf("\nl1");
                postfix[j++]=pop();
            }
            push(ch);
            //printf("\nc1");
            break;

            case '-':
            while(stack[top]=='+'||stack[top]=='-'||stack[top]=='*'||stack[top]=='/')
            {
               // printf("\nl2");
                postfix[j++]=pop();
            }
           // printf("\nc2");
            push(ch);
            break;

            case '*':
            while(stack[top]=='*'||stack[top]=='/')
            {
                //printf("\nl3");
                postfix[j++]=pop();
            }
           // printf("\nc3");
            push(ch);
            break;

            case '/':
            while(stack[top]=='*'||stack[top]=='/')
            {
                //printf("\nl5");
                postfix[j++]=pop();
            }
            //printf("\nc4");
            push(ch);
            break;

            default:
            //printf("\nl5");
            //printf("\nc5");
            postfix[j++]=ch;
        }
        i++;
    }

    while(top!=-1)
    {
       // printf("\nl");
        postfix[j++]=pop();
    }

    postfix[j]='\0';




    printf("\n%s",postfix);

    return 0;
}

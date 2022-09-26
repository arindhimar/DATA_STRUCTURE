#include<stdio.h>
#define N 30

char infix[N],postfix[N],stack[N];
int pos=-1;
char pop()
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

void push(char ch)
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
    printf("\nENTER INFIX       ");
    scanf("%s",&infix);

    char ch,temp;
    int i=0,j=0;

    while (infix[i]!='\0')
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
            
            while(stack[pos]=='+'||stack[pos]=='-'||stack[pos]=='*'||stack[pos]=='/')
            {

                postfix[j++]=pop();
            }
            push(ch);
            break;

            case '-':
            while(stack[pos]=='+'||stack[pos]=='-'||stack[pos]=='*'||stack[pos]=='/')
            {
                postfix[j++]=pop();
            }
            push(ch);
            break;

            case '*':
            while(stack[pos]=='*'||stack[pos]=='/')
            {
                postfix[j++]=pop();
            }
            push(ch);
            break;

            case '/':
            while(stack[pos]=='*'||stack[pos]=='/')
            {
                postfix[j++]=pop();
            }
            push(ch);
            break;

            default:
            postfix[j++]=ch;
            break;
        }
        
        i++;

        
    }

    while(pos!=-1)
    {
        postfix[j++]=pop();
    }

    postfix[j++]='\0';

    printf("\nPOSFIX = %s",postfix);
    


    return 0;
}
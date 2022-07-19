#include<stdio.h>
#define n 4

int a[n],top=-1,value;



void menu()
{
    printf("\n\tMENU");
    printf("\n1 - PUSH");
    printf("\n2 - POP");
    printf("\n3 - DISPLAY");
    printf("\n4 - PEEP");
    printf("\n5 - EXIT");
}

void push()
{
    if(top<n)
    {
        top=top+1;
        printf("\nENTER VALUE TO PUSH           ");
        scanf("%d",&value);
        a[top]=value;
        printf("\nVALUE PUSHED!!\n");
    }
    else
        printf("\nSTACK IS FULL!!\n");
}

void pop()
{
    if(top>=0)
    {
        printf("\nVALUE POPPED = %d",a[top]);
        top=top-1;
        printf("\nVALUE POPPED!!\n");
    }
    else
    {
        printf("\nSTACK IS EMPTY!!\n");
    }
}

void disp()
{
    int i;
    if(top>=0)
    {
        printf("\nSTACK : ");
        for(i=0;i<=top;i++)
        {
            printf("\t%d",a[i]);
        }
    }
    else
        printf("\nSTACK IS EMPTY!!\n");
}

void peep()
{
    int pos;
    if(top>=0)
    {
        printf("\nENTER ELEMENT LOCATION        ");
        scanf("%d",&pos);
        if(pos-1<=top)
        {
            printf("\nELEMENT AT %d = %d",pos,a[top-pos+1]);
        }
        else
            printf("\nINVALID POSITION!!");
    }
    else
        printf("\n STACK IS EMPTY!!");
}

int main()
{
    int opt;
    do
    {
        menu();
        printf("\nSELECT MENU OPTION    ===>>>      ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                disp();
                break;
            case 4:
                peep();
                break;
            case 5:
                break;
            default:
                printf("\nINVALID MENU OPTION");
        }
    }while(opt!=5);
    return 0;
}

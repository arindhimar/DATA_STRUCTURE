#include<stdio.h>
#include<stdlib.h>
#define s1 4
#define s2 3

char stack[s1],cq[s2];
int pos=-1,f=-1,r=-1;

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n1 - PUSH    ");
    printf("\n2 - POP    ");
    printf("\n3 - DISPLAY    ");
    printf("\n4 - EXIT    ");

}

void push()
{
    if(pos==s1-1)
    {
        printf("\nSTACK IS FULL!!");
    }
    else
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&stack[++pos]);
    }
}

void pop()
{
    if(pos==-1)
    {
        printf("\nSTACK IS EMPTY!!");
    }
    else
    {
        if(r==s2-1)
        {
            printf("\nQUEUE IS FULL!!");
        }
        else
        {
            printf("\nr=%d",r);
            r=(r+1)%s2;
            
            printf("\nr=%d",r);
            cq[r]=stack[pos--];
            printf("\nELEMENT POPPED AND PUSHED TO QUEUE IS %d",cq[r]);
        }
    }
}

void disp()
{
    if(pos==-1)
    {
        printf("\nSTACK :   EMPTY!!");
    }
    else
    {
        printf("\nSTACK :");
        for(int i=0;i<=pos;i++)
        {
            printf("\t%d",stack[i]);
        }
    }
    if(f==-1&&r==-1)
    {
        printf("\nQUEUE :   EMPTY!");
    }
    else
    {
        printf("\nQUEUE :");
        for(int j=0;j<=r;j++)
        {
            printf("\t%d",cq[j]);
        }
    }
}

int main()
{
    int opt;
    do
    {
        menu();
        printf("\nENTER MENU OPTION     ===>>>      ");
        scanf("%d",&opt);
        switch (opt)
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
            exit(0);
        default:
        printf("\nINVALID MENU OPTION!!");
            break;
        }
    } while (opt!=4);
    
    return 0;
}

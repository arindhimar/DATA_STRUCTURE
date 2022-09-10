#include<stdio.h>
#include<stdlib.h>
#define N 3

int queue[N],r=-1,f=-1;

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n 1 - INSERT ");
    printf("\n 2 - DELETEF ");
    printf("\n 3 - DELETER ");
    printf("\n 4 - DISPLAY ");
    printf("\n 5 - EXIT ");
}

void insert()
{
    if(r==N-1)
    {
        printf("\nFULL!!");
    }
    else if(f==-1&&r==-1)
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&queue[++r]);
        f=0;
    }
    else
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&queue[++r]);
    }
    printf("%d",r);
    printf("%d",f);
}

void delf()
{
    if(f==-1&&r==-1)
    {
        printf("\nEMPTY!");
    }
    else if(f==r)
    {
        printf("DELETED ELEMENT IS %d",queue[f]);
        f=r=-1;
    }
    else
    {
        printf("DELETED ELEMENT IS %d",queue[f++]);
    }
}

void delr()
{
    if(f==-1&&r==-1)
    {
        printf("\nEMPTY!");
    }
    else if(f==r)
    {
        printf("DELETED ELEMENT IS %d",queue[r]);
        f=r=-1;
    }
    else
    {
        printf("DELETED ELEMENT IS %d",queue[r--]);
    }
}

void disp()
{
    if(r==-1)
    {
        printf("\nEMPTY!!");
    }
    else
    {
        for(int i=f;i<=r;i++)
        {
            printf("\t%d",queue[i]);
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
        insert(); 
        break;
        case 2:
        delf();
        break;
        case 3:
        delr();
        break;
        case 4:
        disp();
        break;
        case 5:
        exit(0);
        break;
        default:
        printf("\nINVALID MENU!!");
            break;
        }

    } while (opt!=5);
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#define N 3

int queue[N],r=-1,f=-1;

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n 1 - INSERT ");
    printf("\n 2 - DELETE ");
    printf("\n 3 - DISPLAY ");
    printf("\n 4 - EXIT ");
}

void insert()
{
    if((r+1)%N==f)
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
        r=(r+1)%N;
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&queue[r]);
    }
    // printf("%d",r);
    // printf("%d",f);
}

void del()
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
        printf("DELETED ELEMENT IS %d",queue[f]);
        f=(f+1)%N;
    }
}

void disp()
{
    if(r==-1&&f==-1)
    {
        printf("\nEMPTY!!");
    }
    else 
    {
        if(f<=r)
        {
            for(int i=f;i<=r;i++){
                printf("\t%d",queue[i]);
            }
        }
        else
        {
            for(int i=0;i<=r;i++){
                printf("\t%d",queue[i]);
            }
            for(int i=f;i<N;i++){
                printf("\t%d",queue[i]);
            }
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
        del();
        break;
        case 3:
        disp();
        break;
        case 4:
        exit(0);
        break;
        default:
        printf("\nINVALID MENU!!");
            break;
        }

    } while (opt!=4);
    
    return 0;
}
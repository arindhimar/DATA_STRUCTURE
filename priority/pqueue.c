#include<stdio.h>
#define N 3

int aqueue[N],bqueue[N],f1=-1,f2=-1,r1=-1,r2=-1;

void  menu()
{

    printf("\n\tMNEU PANEL");
    printf("\n1 - INSERT IN Q(A)");
    printf("\n2 - INSERT IN Q(B)");
    printf("\n3 - DEQUE");
    printf("\n4 - DISPLAY ");
    printf("\n5 - EXIT ");
}


void aenque()
{
    int value;
    if(r1==N-1)
    {
        printf("\nQUEUE A IS FULL!!");
    }
    else
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&value);
        if(f1==-1&&r1==-1)
        {
            aqueue[++r1]=value;
            f1++;
        }
        else
        {
            aqueue[++r1]=value;
        }
    }
}

void benque()
{
    int value;
    if(r2==N-1)
    {
        printf("\nQUEUE B IS FULL!!");
    }
    else
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&value);
        if(f2==-1&&r2==-1)
        {
            bqueue[++r2]=value;
            f2++;
        }
        else
        {
            bqueue[++r2]=value;
        }
    }
}

void deque()
{
    if(r1==-1&&r2==-1)
    {
        printf("\nBOTH QUEUE ARE EMPTY!!");
    }
    else
    {
        if(f1!=-1)
        {
            if(r1==f1)
            {
                printf("\nVALUE DEQUED FROM QUEUE A IS %d",aqueue[f1]);
                f1=-1;
                r1=-1;
            }
            else
            {
                printf("\nVALUE DEQUED FROM QUEUE A IS %d",aqueue[f1]);
                f1++;
            }
        }
        else
        {
            if(r2==f2)
            {
                printf("\nVALUE DEQUED FROM QUEUE B IS %d",bqueue[f2]);
                f2=-1;
                r2=-1;
            }
            else
            {
                printf("\nVALUE DEQUED FROM QUEUE B IS %d",bqueue[f2]);
                f2++;
            }
        }
    }
}

void disp()
{
    int i;
    if(r1==-1&&r2==-1)
    {
        printf("\nQUEUE IS EMPTY!!");
    }
    else
    {
        printf("\nQUEUE A:");
        if(r1!=-1)
        {
            for(i=f1;i<=r1;i++)
            {
                printf("\t%d",aqueue[i]);
            }
        }
        else
        {
            printf("\tEMPTY!!");
        }
        printf("\nQUEUE B:");
        if(r2!=-1)
        {
            for(i=f2;i<=r2;i++)
            {
                printf("\t%d",bqueue[i]);
            }
        }
        else
        {
            printf("\tEMPTY!!");
        }
    }
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
            aenque();
            break;
        case 2:
            benque();
            break;
        case 3:
            deque();
            break;
        case 4:
            disp();
            break;
        case 5:
            exit(0);
        default:
            printf("\nINVALID MNEU OPTION");
        }

    }while(opt!=5);

    return 0;
}

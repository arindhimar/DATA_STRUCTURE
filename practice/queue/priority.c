#include<stdio.h>
#include<stdlib.h>
#define N 3

int queuea[N],queueb[N],ra=-1,fa=-1,rb=-1,fb=-1;

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n 1 - INSERT(A) ");
    printf("\n 2 - INSERT(B) ");
    printf("\n 3 - DELETE ");
    printf("\n 4 - DISPLAY ");
    printf("\n 5 - EXIT ");
}

void inserta()
{
    if(ra==N-1)
    {
        printf("\nFULL!!");
    }
    else if(fa==-1&&ra==-1)
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&queuea[++ra]);
        fa=0;
    }
    else
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&queuea[++ra]);
    }
}

void insertb()
{
    if(rb==N-1)
    {
        printf("\nFULL!!");
    }
    else if(fb==-1&&rb==-1)
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&queueb[++rb]);
        fb=0;
    }
    else
    {
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&queueb[++rb]);
    }
}

void del()
{
    if(rb==-1&&ra==-1)
    {
        printf("\nBOTH QUEUE ARE EMPTY!!");
    }
    else
    {
        if(fa!=-1)
        {
            if(ra==fa)
            {
                printf("\nVALUE DEQUED FROM QUEUE A IS %d",queuea[fa]);
                fa=ra=-1;
            }
            else
            {
                printf("\nVALUE DEQUED FROM QUEUE A IS %d",queuea[fa]);
                fa++; 
            }
        }
        else
        {
            if(rb==fb)
            {
                printf("\nVALUE DEQUED FROM QUEUE B IS %d",queueb[fb]);
                fb=rb=-1;
            }
            else
            {
                printf("\nVALUE DEQUED FROM QUEUE B IS %d",queueb[fb]);
                fb++;                 
            }
        } 
    }
}

void disp()
{
    if(rb==-1&&ra==-1)
    {
        printf("\nQ[A] = ");
        printf("EMPTY!");
        printf("\nQ[B] = ");
        printf("EMPTY!\n");
    }
    else
    {
        if(fa!=-1)
        {
            printf("\nQ[A] = ");
            for(int i=fa;i<=ra;i++)
            {
                printf("\t%d",queuea[i]);
            }
        }
        else
        {
            printf("\nQ[A] = EMPTY!!");
        }
        if(fb!=-1)
        {
            printf("\nQ[A] = ");
            for(int i=fb;i<=rb;i++)
            {
                printf("\t%d",queueb[i]);
            }
        }
        else
        {
            printf("\nQ[B] = EMPTY!!");
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
        inserta(); 
        break;
        case 2:
        insertb();
        break;
        case 3:
        del();
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
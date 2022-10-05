#include<stdio.h>
#include<stdlib.h>
#define ma (struct node *)malloc(sizeof(struct node))
#define mi (struct nodei *)malloc(sizeof(struct nodei))
#define mc (struct nodec *)malloc(sizeof(struct nodec))

struct node
{
    int valuei;
    char valuec[1];
    struct node *next;
}*f=NULL,*l=NULL,*temp;

struct nodei
{
    int ival;
    struct nodei *ni;
}*fi=NULL,*li=NULL,*tempi;

struct nodec
{
    char cval[1];
    struct nodei *nc;
}*fc=NULL,*lc=NULL,*tempc;

void menu()
{
    printf("\n 1 - Insert");
    printf("\n 2 - Display");
    printf("\n 3 - Diverge");
    printf("\n 4 - Exit");
}

void insert()
{
    temp=ma;
    printf("\nEnter int value       ");
    scanf("%d",&temp->valuei);
    printf("\nEnter char value       ");
    scanf("%s",temp->valuec);
    temp->next=NULL;
    if(f==NULL&&l==NULL)
    {
        f=l=temp;
    }
    else
    {
        l->next=temp;
        l=temp;
    }
}

void disp()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        printf("\n INT :    ");
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\t %d",temp->valuei);
           
        }
        printf("\n CHAR :    ");
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\t %c",temp->valuec[0]);
        }

    }
}

void diverge()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            tempi=mi;
            tempc=mc;

            tempi->ival=temp->valuei;
            tempc->cval[0]=temp->valuec[0];

            tempi->ni=NULL;
            tempc->nc=NULL;

            if(fi==NULL&&fc==NULL)
            {
                fi=li=tempi;
                fc=lc=tempc;
            }
            else
            {
                li->ni=tempi;
                li=tempi;
                lc->nc=tempc;
                lc=tempc;
            }
        }
        printf("\nDiverged Int");
        for(tempi=fi;tempi!=NULL;tempi=tempi->ni)
        {
            printf("\t%d",tempi->ival);
        }
        printf("\nDiverged Char");
        for(tempc=fc;tempc!=NULL;tempc=tempc->nc)
        {
            printf("\t%c",tempc->cval[0]);
        }
    }
}

int main()
{
    int opt;
    do
    {
        menu();
        printf("\nSelect Menu Option        ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            insert();
            break;
            case 2:
            disp();
            break;
            case 3:
            diverge();
            break;
            case 4:
            exit(0);
        }
    }while(opt!=4);
    return 0;
}
/*
    Date    : 22-11-2022
    Day     : Tuesday
    Code    : Demerge
    Author  : Arin Dhimar
*/

#include<stdio.h>
#include<stdlib.h>
#define ma (struct node*)malloc(sizeof(struct node))
#define mai (struct nodei*)malloc(sizeof(struct nodei))
#define mac (struct nodec*)malloc(sizeof(struct nodec))

struct node
{
    int ivalue;
    char cvalue[1];
    struct node *next;
}*f=NULL,*l=NULL,*temp;

struct nodei
{
    int value;
    struct nodei *next;
}*fi=NULL,*li=NULL,*tempi;

struct nodec
{
    char value[1];
    struct nodec *next;
}*fc=NULL,*lc=NULL,*tempc;

void menu()
{
    printf("\n1 - Insert");
    printf("\n2 - Demerge");
    printf("\n3 - Display");
    printf("\n4 - Exit");
}

void insert()
{
    temp=ma;
    printf("\nEnter 'int' Value         ");
    scanf("%d",&temp->ivalue);
    printf("\nEnter 'char' Value        ");
    scanf("%s",&temp->cvalue[0]);
    temp->next=NULL;

    if(f==NULL)
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
    printf("\nMain Link List    :   ");
    if(f==NULL)
    {
        printf("Empty!!");
    }
    else
    {
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\n");
            printf("\n'int'     :    %d",temp->ivalue);
            printf("\n'char'    :    %c",temp->cvalue[0]);
        }
    }
    printf("\n\n'int' Link List   :   ");
    if(fi==NULL)
    {
        printf("Empty!!");
    }
    else
    {
        for(tempi=fi;tempi!=NULL;tempi=tempi->next)
        {
            printf("\n 'int' Value      :       %d",tempi->value);
        }
    }
    printf("\n\n'char' Link List   :   ");
    if(fc==NULL)
    {
        printf("Empty!!");
    }
    else
    {
        for(tempc=fc;tempc!=NULL;tempc=tempc->next)
        {
            printf("\n 'char' Value      :       %c",tempc->value[0]);
        }
    }
}

void demerge()
{
    if(f==NULL)
    {
        printf("\nMain Link List is Empty!!");
    }
    else
    {
        if(fi==li&&fi!=NULL)
        {
            printf("\n1");
            free(fc);
            free(lc);
            fi=li=NULL;
            fc=lc=NULL;
        }
        else if(fi!=li&&fi!=NULL)
        {
            struct nodec *pc;
            for(tempc=fc;tempc!=NULL;tempc=tempc->next)
            {
                if(tempc==lc)
                {
                    free(lc);
                    break;
                }
                printf("2c");
                pc=tempc;
                free(pc);
            }
            fc=lc=NULL;
            struct nodei *pi;
            printf("\n2");
            for(tempi=fi;tempi!=NULL;tempi=tempi->next)
            {
                if(tempi==li)
                {
                    free(li);
                    break;
                }
                printf("2i");
                pi=tempi;
                free(pi);
            }
            fi=li=NULL;

        }
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            tempi=mai;
            tempc=mac;
            tempi->value=temp->ivalue;
            tempi->next=NULL;
            tempc->value[0]=temp->cvalue[0];
            tempc->next=NULL;
            if(fi==NULL&&fc==NULL)
            {
                fi=li=tempi;
                fc=lc=tempc;
            }
            else
            {
                li->next=tempi;
                li=tempi;
                lc->next=tempc;
                lc=tempc;
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
        printf("\nEnter Menu Option         ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            insert();
            break;
            case 2:
            demerge();
            break;
            case 3:
            disp();
            break;
            case 4:
            break;
        }
    }while(opt!=4);
    return 0;
}
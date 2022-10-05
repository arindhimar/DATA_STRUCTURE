#include<stdio.h>
#include<stdlib.h>
#define ma (struct student*)malloc(sizeof(struct student))

struct student
{
    int rno,total;
    char name[10];
    struct student *next;
}*f=NULL,*l=NULL,*temp,*p;

void menu()
{
    printf("\nMenu Panel");
    printf("\n 1 - Insert");
    printf("\n 2 - Delete By Roll Number");
    printf("\n 3 - Display");
    printf("\n 4 - Display Total >= 75");
    printf("\n 5 - Exit");
}

void create()
{
    int x;
    choice:

    printf("\nEnter -1 to exit creation     ");
    scanf("%d",&x);

    while(x!=-1)
    {
        temp=ma;
        printf("\nEnter Roll Number     ");
        scanf("%d",&temp->rno);
        printf("\nEnter Name     ");
        scanf("%s",temp->name);
        printf("\nEnter Total     ");
        scanf("%d",&temp->total);
        temp->next=NULL;

        if(f==NULL)
        {
            f=l=temp;
        }
        else
        {
            l->next=temp;
            l=temp;
            l->next=NULL;
        }

        goto choice;
    }
}

void disp()
{
    if(f==NULL)
    {
        printf("\nList is Empty!!");
    }
    else
    {
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\nROLL NO   =   %d",temp->rno);
            printf("\nNAME      =   %s",temp->name);
            printf("\nTOTAL     =   %d",temp->total);
        }
    }
}

void dispc()
{
    if(f==NULL)
    {
        printf("\nList is Empty!!");
    }
    else
    {
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            if(temp->total>=75)
            {
                printf("\nROLL NO   =   %d",temp->rno);
                printf("\nNAME      =   %s",temp->name);
                printf("\nTOTAL     =   %d",temp->total);
            }
        }
    }
}

void delete()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is Empty!!");
    }
    else
    {
        int x,ck=0;
        printf("\nEnter Roll no to delete   ");
        scanf("%d",&x);

        if(f->rno==x)
        {
            ck=1;
            temp=f;
            printf("\nDeleted Info Details  :   ");
            printf("\nROLL NO   =   %d",temp->rno);
            printf("\nNAME      =   %s",temp->name);
            printf("\nTOTAL     =   %d",temp->total);
            f=f->next;
            free(temp);
        }
        else if(l->rno==x)
        {
            ck=1;
            temp=l;
            printf("\nDeleted Info Details  :   ");
            printf("\nROLL NO   =   %d",temp->rno);
            printf("\nNAME      =   %s",temp->name);
            printf("\nTOTAL     =   %d",temp->total);
            for(temp=f;temp->next!=l;temp=temp->name);
            free(temp->next);
            temp->next=NULL;
            l=temp;
        }
        else
        {
            for(temp=f;temp!=NULL;temp=temp->next)
            {
                if(temp->rno==x)
                {
                    printf("\nDeleted Info Details  :   ");
                    printf("\nROLL NO   =   %d",temp->rno);
                    printf("\nNAME      =   %s",temp->name);
                    printf("\nTOTAL     =   %d",temp->total);

                    p->next=temp->next;
                    free(temp);
                    ck=1;
                    break;
                }
                p=temp;
            }
            if(ck==0)
            {
                printf("\nRoll no not  found!!");
            }
        }

    }
}


int main()
{
    create();
    int opt;
    do
    {
        menu();
        printf("\nSelect Menu Option       ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            create();
            break;
            case 2:
            delete();
            break;
            case 3:
            disp();
            break;
            case 4:
            dispc();
            break;
            case 5:
            exit(0);
            default:
            printf("\nInvalid Menu Option!!");
        }
    }while(opt!=5);
}
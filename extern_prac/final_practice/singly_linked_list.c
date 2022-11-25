/*
    Author  :   Arin Dhimar
    Date    :   25-11-2022
    Code    :   Singly_Linked_List
*/

#include<stdio.h>
#include<stdlib.h>
#define ma (struct node*)malloc(sizeof(struct node))

struct node
{
    int value;
    struct node *next;
}*f=NULL,*l=NULL,*temp;

void menu()
{
    printf("\n 1 - Create");
    printf("\n 2 - Delete");
    printf("\n 3 - Search");
    printf("\n 4 - Sort");
    printf("\n 5 - Display");
    printf("\n 6 - Exit");
}

void create()
{
    temp=ma;
    printf("\nEnter value to insert     ");
    scanf("%d",&temp->value);
    temp->next=NULL;
    if(f==NULL)
    f=l=temp;
    else
    {
        l->next=temp;
        l=temp;
    }
}

void disp()
{
    if(f==NULL)
    {
        printf("\nEMpty!!");
    }
    else
    {
        printf("\nLL    :   ");
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("%d\t",temp->value);
        }
    }
}

void del()
{
    if(f==NULL)
    {
        printf("\nEMpty!!");
    }
    else
    {
        int opt;
        printf("\nEnter Value to Delete     ");
        scanf("%d",&opt);

        if(f->value==opt&&f==l)
        {
            printf("\nValue Deleted!!");
            free(f);
            f=l=NULL;
            return;
        }
        else if(f->value==opt)
        {
            temp=f;
            printf("\nValue Deleted!!");
            f=f->next;
            free(temp);
            return;
        }
        else if(l->value==opt)
        {
            printf("\nValue Deleted!!");
            for(temp=f;temp->next!=l;temp=temp->next);
            free(l);
            temp->next=NULL;
            l=temp;
            return;
        }
        else
        {
            struct node *p,*c;
            for(c=f;c!=NULL;c=c->next)
            {
                if(c->value==opt)
                {
                    printf("\nValue Deleted!!");
                    p->next=c->next;
                    free(c);
                    return;
                }
                p=c;
            }

        }
        printf("\nNo Value Found!!");

    }
}

void search()
{
    if(f==NULL)
    {
        printf("\nEMptyy!!");
    }
    else
    {
        int opt;
        printf("\nEnter value to search     ");
        scanf("%d",&opt);
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            if(temp->value==opt)
            {
                printf("\n Value found at %u",&temp);
                return;
            }
        }
        printf("\nValue not found!!");
    }
}

void sort()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else if(f==l)
    {
        printf("\nSorted!!");
    }
    else
    {
        struct node *p,*c;
        for(c=f;c!=NULL;c=c->next)
        {
            for(p=c->next;p!=NULL;p=p->next)
            {
                if(c->value>p->value)
                {
                    temp->value=c->value;
                    c->value=p->value;
                    p->value=temp->value;
                }
            }
        }
        printf("\nSorted!!");
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
            create();
            break;
            case 2:
            del();
            break;
            case 3:
            search();
            break;
            case 4:
            sort();
            break;
            case 5:
            disp();
            break;
            case 6:
            break;
        }
    }while(opt!=6);
    return 0;
}
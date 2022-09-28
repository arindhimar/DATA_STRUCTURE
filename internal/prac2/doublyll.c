#include<stdio.h>
#include<stdlib.h>
#define ma (struct node *)malloc(sizeof(struct node))

struct node
{
    int value;
    struct node *prev,*next;
}*f=NULL,*l=NULL,*p,*c,*temp;

void menu()
{
    printf("\nMenu Panel");
    printf("\n1 - Insert First");
    printf("\n2 - Insert Last");
    printf("\n3 - Insert By Position");
    printf("\n4 - Delete First");
    printf("\n5 - Delete Last");
    printf("\n6 - Delete By Position");
    printf("\n7 - Search");
    printf("\n8 - Sort");
    printf("\n9 - Display From First");
    printf("\n10 - Display From Last");
    printf("\n11 - Exit");
}
static int pos=0;

void insertfirst()
{
    pos=pos+1;
    temp=ma;
    printf("\nEnter value to insert     ");
    scanf("%d",&temp->value);
    temp->prev=NULL;
    temp->next=NULL;
    if(f==NULL&&l==NULL)
    {
        f=l=temp;
    }
    else
    {
        temp->next=f;
        f->prev=temp;
        f=temp;
    }

}

void insertlast()
{
    pos=pos+1;

    temp=ma;
    printf("\nEnter value to insert     ");
    scanf("%d",&temp->value);
    temp->prev=NULL;
    temp->next=NULL;
    if(f==NULL&&l==NULL)
    {
        f=l=temp;
    }
    else
    {
        l->next=temp;
        temp->prev=l;
        l=temp;
    }

}

void insertbypos()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nValue will be inserted at first place");
    }
    else
    {
        int x;
        printf("\nEnter position to insert node ");
        scanf("%d",&x);

        if(x>0&&x<=pos+1)
        {
            if(x==1)
            {
                insertfirst();
            }
            else if(x==pos+1)
            {
                insertlast();
            }
            else
            {
                pos=pos+1;
                c=f;
                for(int i=1;i<x;i++)
                {
                    p=c;
                    c=c->next;
                }

                temp=ma;
                printf("\nEnter Value to insert     ");
                scanf("%d",&temp->value);

                temp->next=c;
                temp->prev=c->prev;

                c->prev=temp;
                p->next=temp;

            }
        }
        else
        {
            printf("\nInvalid position ");
        }

    }
}

void create()
{
    int x;
    choice:
    printf("\nEnter -1 to exit creation     ");
    scanf("%d",&x);
    while(x!=-1)
    {
        insertlast();
        goto choice;
    }
}

void disp()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is empty!");
    }
    else
    {
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\t%d",temp->value);
        }
    }
}

void delfirst()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is empty!!");
    }
    else
    {
        pos=pos-1;
        printf("\nDeleted Element is %d",f->value);
        if(f==l)
        {
            free(f);
            f=l=NULL;
        }
        else
        {
            f=f->next;
            free(f->prev);
            f->prev=NULL;
        }
    }
}

void dellast()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is empty!!");
    }
    else
    {
        pos=pos-1;
        printf("\nDeleted Element is %d",l->value);
        if(f==l)
        {
            free(f);
            f=l=NULL;
        }
        else
        {
            l=l->prev;
            free(l->next);
            l->next=NULL;
        }
    }
}

void delbypos()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is empty!!");
    }
    else
    {
        int x;
        printf("\nEnter position to delete      ");
        scanf("%d",&x);

        if(x>0&&x<pos+1)
        {
            if(x==1)
            {
                delfirst();
            }
            else if(x==pos+1)
            {
                dellast();
            }
            else
            {
                
                pos=pos-1;
                c=f;
                for(int i=1;i<x;i++)
                {
                    p=c;
                    c=c->next;
                }

                printf("\nDeleted Value is %d",c->value);

                p->next=c->next;
                free(c);
            }
        }
    }
}

void disprev()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is empty!!");

    }
    else
    {
        for(temp=l;temp!=NULL;temp=temp->prev)
        {
            printf("\t%d",temp->value);
        }
    }
}

void search()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is empty!!");
    }
    else
    {
        int x;
        printf("\nENter value to serach     ");
        scanf("%d",&x);

        for(temp=f;temp!=NULL;temp=temp->next)
        {
            if(temp->value==x)
            {
                printf("\nValue Found at %u",temp);
                return;
            }
        }
        printf("\nValue not Found!!");
    }
}

void sort()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nLIst is empty!!");
    }
    else
    {
        if(f!=l)
        {
            temp=ma;
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
        printf("\nSelect Menu option        ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            insertfirst();
            break;
            case 2:
            insertlast();
            break;
            case 3:
            insertbypos();
            break;
            case 4:
            delfirst();
            break;
            case 5:
            dellast();
            break;
            case 6:
            delbypos();
            break;
            case 7:
            search();
            break;
            case 8:
            sort();
            break;
            case 9:
            disp();
            break;
            case 10:
            disprev();
            break;
            case 11:
            exit(0);
        }
    }while(opt!=11);
}
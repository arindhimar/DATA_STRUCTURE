#include<stdio.h>
#include<stdlib.h>
#define ma (struct node *)malloc (sizeof(struct node))

struct node
{
    int value;
    struct node *next;
}*f=NULL,*l=NULL,*temp,*nn,*p,*c;

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

void inertfirst()
{
    pos=pos+1;
    temp=ma;
    printf("\nEnter value to insert     ");
    scanf("%d",&temp->value);
    temp->next=NULL;

    if(f==NULL&&l==NULL)
    {
        f=l=temp;
        f->next=l;
    }
    else
    {
        l->next=temp;
        temp->next=f;
        f=temp;
    }

}

void insertlast()
{
    pos=pos+1;

    temp=ma;
    printf("\nEnter value to insert     ");
    scanf("%d",&temp->value);
    temp->next=NULL;
    if(f==NULL&&l==NULL)
    {
        f=l=temp;
        f->next=l;
    }
    else
    {
        l->next=temp;
        temp->next=f;
        l=temp;
    }

}

void insertbypos()
{


    if(f==NULL&&l==NULL)
    {
        printf("\nElement will be inserted at first position ");
        inertfirst();
        return;
    }

    int x;
    printf("\nEnter position to insert node     ");
    scanf("%d",&x);

    if(x>0&&x<=pos+1)
    {
        temp=ma;
        printf("\nEnter value to insert     ");
        scanf("%d",&temp->value);

        if(x==1)
        {
            inertfirst();
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

            temp->next=p->next;
            p->next=temp;
        }

    }
    else
    {
        printf("\nInvalid position!!");
    }

    

}

void create()
{
    int x;
    choice:
    printf("Enter -1 to exit creation   ");
    scanf("%d",&x);
    while(x!=-1)
    {
        insertlast();
        goto choice;
    }
}

void delfirst()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        pos=pos-1;
        if(f==l)
        {
            printf("\nDeleted Element is %d",f->value);
            free(f);
            f=l=NULL;
        }
        else
        {
            temp=f;
            printf("\nDeleted Element is %d",f->value);
            f=f->next;
            l->next=f;
            free(temp);
        }
    }
}

void dellast()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        pos=pos-1;
        if(f==l)
        {
            printf("\nDeleted Element is %d",l->value);
            free(f);
            f=l=NULL;
        }
        else
        {
            for(temp=f;temp->next!=l;temp=temp->next);

            printf("\nDeleted Element Is %d",l->value);

            free(temp->next);
            l=temp;
            l->next=f;
        }
    }
}

void delbypos()
{
    if(f==l)
    {
        printf("\nFirst value will be Deleted");
        delfirst();
    }
    else
    {
        int x;
        printf("\nEnter position to delete      ");
        scanf("%d",&x);

        if(x>0&&x<=pos+1)
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
                printf("\nVa;ue deleted is %d",c->value);
                p->next=c->next;
                free(c);
            }
        }
    }
}


void dispf()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is empty!!");
    }
    else if(f==l)
    {
        printf("\t%d",f->value);
    }
    else
    {
        temp=f;
        do
        {
            printf("\t%d",temp->value);
            temp=temp->next;
        }while(temp!=f);
    }
}

void displ()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nEmpty!!");
    }
    else if(f==l)
    {
        printf("\t%d",f->value);
    }
    else
    {
        temp=l;
        do
        {
            printf("\t%d",temp->value);
            temp=temp->next;
        }while(temp!=l);
    }
}

void search()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        int x;
        printf("\nEnter value to search     ");
        scanf("%d",&x);
        if(f!=l)
        {
            if(x==f->value)
            {
                printf("Value found at %u",f);
                return;
            }
            else
            {
                temp=f;
                do
                {
                    if(x==temp->value)
                    {
                        printf("\nValue found at %u",temp);
                        return;
                    }
                    temp=temp->next;
                }while(temp!=f);
            }
        }
    }
    printf("\nValue not found!!");
}

void sort()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is emptyy!!");
    }
    else
    {
        if(f!=l)
        {
            temp=ma;
            for(c=f;c!=l;c=c->next)
            {
                for(p=c->next;p!=l;p=p->next)
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
    int opt;
    create();
    do
    {
        menu();
        printf("\nSelect Menu Option        ");
        scanf("%d",&opt);

        switch(opt)
        {
            case 1:
            inertfirst();
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
            dispf();
            break;
            case 10:
            displ();
            break;
            case 11:
            exit(0);
        }

    }while(opt!=11);
}
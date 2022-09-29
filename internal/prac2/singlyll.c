#include<stdio.h>
#include<stdlib.h>
#define ma (struct node *)malloc(sizeof(struct node))

struct node
{
    int value;
    struct node *next;  
}*f=NULL,*l=NULL,*p,*c,*temp,*nn;

static int pos=0;

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
    printf("\n9 -  Display");
    printf("\n10 - Exit");
    printf("\n11 - Delete By Position From Last");

}



void insertfirst()
{
    temp=ma;
    pos=pos+1;
    printf("\nEnter value to insert     ");
    scanf("%d",&temp->value);
    temp->next=NULL;
    if(f==NULL&&l==NULL)
    {
        f=l=temp;
    }
    else
    {
        temp->next=f;
        f=temp;
    }
}

void insertlast()
{
    pos=pos+1;
    temp=ma;
    printf("\nEnetr value to insert     ");
    scanf("%d",&temp->value);
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

void insertbypos()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nElement will be inserted to first position!!");
        insertfirst();
    }
    else
    {
        int x;
        printf("\nEnter position to delete      " );
        scanf("%d",&x);
        if(x>0&&x<=pos+1)
        {
            temp=ma;
            printf("\nEnter value to Insert     ");
            scanf("%d",&temp->value);
            temp->next=NULL;

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

                p->next=temp;
                temp->next=c;
            }
        }
        else
        {
            printf("\nInvalid position number!!");
        }
    }

}

void disp()
{
    if(f==NULL&l==NULL)
    {
        printf("\nEmpty!!");

    }
    else
    {
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\t%d",temp->value);
        }
    }
}

void creation()
{
    int q;
    crt:
    printf("\nEnter -1 to exit creation!!");
    scanf("%d",&q);
    while(q!=-1)
    {
        insertlast();
        goto crt;
    }
}

void delfirst()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is Empty!!");
    }
    else
    {
        pos=pos-1;
        printf("\nDeleted Element Is %d",f->value);

        if(f==l)
        {
            free(f);
            f=l=NULL;
            return;
        }

        printf("\nDeleted Element Is %d",f->value);
        temp=f;
        f=f->next;
        free(temp);
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
        printf("\nDeleted Element is %d",l->value);
        if(f==l)
        {
            free(f);
            f=l=NULL;
            return;
        }
        
        for(c=f;c!=l;c=c->next)
        {
            p=c;
        }

        free(l);
        l=p;
        l->next=NULL;
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
        printf("\nEnter position to delete        ");
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
                printf("\nDeleted Element is %d",c->value);

                p->next=c->next;
                free(c);
            }
        }
        else
        printf("\nInvalid position number!!");

    }
}

void delbyposlast()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        int m;
        printf("Enter pos");
        scanf("%d",&m);

        int n=pos-m;
        printf("Res=%d",n);
        c=f;
        int i=1;
        do
        {
            p=c;
            c=c->next;
        }while(i<=n);
                printf("\nDeleted Element is %d",c->value);

                p->next=c->next;
                free(c);

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
    creation();
    int opt;
    do
    {
        menu();
        printf("\nSelect Menu Option        ");
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
            exit(0);
            case 11:
            delbyposlast();
        }
    }while(opt!=10);
    return 0;
}
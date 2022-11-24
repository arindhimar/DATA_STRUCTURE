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
    printf("\n1 - Create");
    printf("\n2 - Delete");
    printf("\n3 - Display");
    printf("\n4 - Search");
    printf("\n5 - Sort");
    printf("\n6 - Exit");
}

void create()
{
    temp=ma;
    printf("\nEnter new Value       ");
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
        printf("\nEmpty!!");
    }
    else
    {
        printf("\nLL:");
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\t%d",temp->value);
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
        int opt,ck=0;
        printf("\nEnter value to delete     ");
        scanf("%d",&opt);
        
        if(f->value==opt)
        {
            ck=1;
            printf("\nValue Deleted is %d",f->value);
            temp=f;
            f=f->next;
            free(temp);
        }
        else if(l->value==opt)
        {
            ck=1;
            printf("\nDeleted Value is %d",l->value);
            for(temp=f;temp->next!=l;temp=temp->next);
            free(l);
            temp->next=NULL;
            l=temp;
        }
        else
        {
            struct node *p,*c;
            for(c=f;c!=NULL;c=c->next)
            {
                if(c->value==opt)
                {
                    ck=1;
                    break;
                }
                p=c;
            }
            if(ck==1)
            {
                printf("\nDeleted Value is %d",c->value);
                p->next=c->next;
                free(c);
            }
        }
        if(ck==0)
        {
            printf("\nNo value found!!");
        }
    }
}

void search()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        int opt;
        printf("\nEnter value to search     ");
        scanf("%d",&opt);
        for(temp=c;temp!=NULL;temp=temp->next)
        {
            if(temp->value==opt)
            {
                printf("\nValue Found at %u",&temp);
                return;
            }
        }
        printf("\nVaue not found!!");
    }
}

void sort()
{
    if(f==NULL)
    {
        printf("\nEmpty!!")
    }
    else if(f!=l)
    {
        int opt;
        struct node *p,*c;
        for(c=f;c!=NULL;c=c->next)
        {
            for(p=c->next;c!=NULL;c=c->next)
            {
                if(c->value>p->value)
                {
                    opt=c->value;
                    c->value=p->value;
                    p->value=opt;
                }
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
            disp();
            break;
            case 4:
            search();
            break;
            case 5:
            sort();
            break;
            case 6:
            break;
        }
    }while(opt!=6);
    return 0;
}
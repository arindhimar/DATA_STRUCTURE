#include<stdio.h>
#include<stdlib.h>
#define ma (struct node*)malloc(sizeof(struct node))

struct node
{
    int data;
    struct node *next;
}*f,*l,*temp;

int ct=0;

void menu()
{
    printf("\n\tMenu Panel");
    printf("\n1 - Insert at First Position");
    printf("\n2 - Insert at Last Position");
    printf("\n3 - Insert by Position Number");
    printf("\n4 - Delete at First Position");
    printf("\n5 - Delete at Last Position");
    printf("\n6 - Delete by Position Number");
    printf("\n7 - Display");
    printf("\n8 - Exit");
    printf("\n9 - Sort");
}

void insertfirst()
{
    ct++;
    temp=ma;
    printf("\nEnter value for new node      ");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(f==NULL)
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
    ct++;
    temp=ma;
    printf("\nEnter value for new node      ");
    temp->next=NULL;
    scanf("%d",&temp->data);
    if(l==NULL)
    {
        f=l=temp;
    }
    else
    {
        l->next=temp;
        l=temp;
    }
}

void sort()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else if (f==l)
    {
        printf("\nSorted!!");
    }
    else
    {
        int opt;
        struct node *p,*c;
        for(c=f;c!=NULL;c=c->next)
        {
            for(p=c->next;p!=NULL;p=p->next)
            {
                if(c->data>p->data)
                {
                    opt=c->data;
                    c->data=p->data;
                    p->data=opt;
                }
            }
        }
        printf("\nSorted!!");
    }
    
}

void insertpos()
{
    int pos;
    printf("\nEnter position to insert node     ");
    scanf("%d",&pos);

    if(pos>0&&pos<ct+2)
    {
        if(pos==1)
        insertfirst();
        else if(pos==ct+1)
        insertlast();
        else
        {
            ct++;
            struct node *p,*c;
            temp=ma;
            c=f;
            for (int i=1;i<pos;i++)
            {
                p=c;
                c=c->next;
                //printf("\nnn%d",c->data);

            }
            printf("\nEnter value for new node      ");
            scanf("%d",&temp->data);
            temp->next=p->next;
            p->next=temp;
        }

    }
    else
    printf("\nInvalid position number");
}

void create()
{
    int choice;
    do
    {
        insertlast();
        printf("\nENter 0 to exit creation      ");
        scanf("%d",&choice);
    }while(choice!=0);
}

void delfirst()
{
    if(f==NULL)
    {
        printf("\nEMpty!!");
    }
    else
    {
        ct--;
        printf("\nDeleted Node Value is %d",f->data);
        if(f==l)
        {
            free(f);
            f=l=NULL;
        }
        else
        {
            temp=f;
            f=f->next;
            free(temp);
        }
    }
}

void dellast()
{
    if(l==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        ct--;
        printf("\nDleted Node Value is %d",l->data);
        if(f==l)
        {
            free(l);
            f=l=NULL;
        }
        else
        {
            for(temp=f;temp->next!=l;temp=temp->next);
            free(temp->next);
            l=temp;
            l->next=NULL;
        }
    }

}

void delbypos()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        int pos;
        printf("\nEnter position to delete      ");
        scanf("%d",&pos);
        if(pos>0 && pos< ct+2)
        {
            if(pos==1)
            delfirst();
            else if (pos==ct+1)
            dellast();
            else
            {
                ct--;
                struct node *p,*c;
                c=f;
                for(int i=1;i<pos;i++)
                {
                    p=c;
                    c=c->next;
                    //printf("\npp%d",p->data);
                }
                printf("\nDleted Value is %d",c->data);
                p->next=c->next;
                free(c);
            }
        }
    }
}

void disp()
{
    printf("\n");
    if(f==NULL)
    {
        printf("\nEmpty!");
    }
    else
    {
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\t%d",temp->data);
        }
    }
}



int main()
{
    //printf("\nHello World!!");
    create();
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
            insertpos();
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
            disp();
            break;
            case 8:
            exit(0);
            break;
            case 9:
            sort();
            break;
            default:
            printf("\nInvalid Menu Option!");
        }
    }while(opt!=8);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#define ma (struct node *)malloc(sizeof(struct node))

struct node
{
    int value;
    struct node *next;
}*first=NULL,*last=NULL,*temp,*nn,*p,*c;

static int ct=0;

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n1 - INSERT AT FIRST");
    printf("\n2 - INSERT BY POSITION");
    printf("\n3 - INSERT AT LAST");
    printf("\n4 - DELETE AT FIRST");
    printf("\n5 - DELETE BY POSITION");
    printf("\n6 - DELETE AT LAST");
    printf("\n7 - SEARCH ELEMENT");
    printf("\n8 - SORT LIST");
    printf("\n9 - DISPLAY");
    printf("\n10 - EXIT");
}

//initial creation of list
void create()
{
    int choice;

    printf("\nENTER [-1] TO EXIT OR ANYTHING ELSE TO CREATE NODE    ");
    scanf("%d",&choice);

    while(choice!=-1)
    {
        ct++;
        nn=ma;

        printf("\nENTER VALUE   ");
        scanf("%d",&nn->value);

        nn->next=NULL;

        if(first==NULL)
        {
            first=last=nn;
        }
        else
        {
            last->next=nn;
            last=nn;
        }
            printf("\nENTER [-1] TO EXIT OR ANYTHING ELSE TO CREATE NODE    ");
        scanf("%d",&choice);
    }

}

void display()
{
    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!!!");
    }
    else
    {
        temp=first;

        for(temp=first;temp->next!=NULL;temp=temp->next)
        {
            printf("\t%d",temp->value);
        }
        printf("\t%d",temp->value);
    }

}

void insertfirst()
{
    ct++;
    nn=ma;
    printf("\nENTER VALUE   ");
    scanf("%d",&nn->value);
    nn->next=NULL;
    if(first==NULL)
    {
        first=last=nn;
    }
    else
    {
        nn->next=first;
        first=nn;
    }
}

void insertlast()
{
    ct++;
    nn=ma;
    printf("\nENTER VALUE   ");
    scanf("%d",&nn->value);
    nn->next=NULL;
    if(first==NULL)
    {
        first=last=nn;
    }
    else
    {
        last->next=nn;
        last=nn;
    }
}

void insertpos()
{
    int pos;

    printf("\nENTER POSITION TO INSERT  ");
    scanf("%d",&pos);

    if(pos==1)
    {
        insertfirst();
    }
    else if(pos==ct+1)
    {
        insertlast();
    }
    else if(pos<=0||pos>ct)
    {
        printf("\nINVALID POSITION!!");
    }
    else
    {
        ct++;
        nn=ma;
        printf("\nENTER VALUE   ");
        scanf("%d",&nn->value);
        nn->next=NULL;
        c=first;
        for(int i=1;i<pos;i++)
        {
            p=c;
            c=c->next;
        }

        p->next=nn;
        nn->next=c;

    }

}



void deletefirst()
{

    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!!");
    }
    else if(first->next==NULL)
    {
        ct--;
        printf("\nDELETED ELEMENT IS %d",first->value);
        free(last);
        first=last=NULL;
    }
    else
    {
        ct--;
        printf("\nDELETED ELEMENT IS %d",first->value);
        temp=first->next;
        free(first);
        first=temp;
    }
}

void deletelast()
{

    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!!");
    }
    else
    {
        ct--;
        c=first;
        p=NULL;
        if(first->next==NULL)
        {
            printf("\nDELETED ELEMENT IS %d",c->value);
            free(last);
            first=last=NULL;
        }
        else
        {
            while(c->next!=NULL)
            {
                p=c;
                c=c->next;
            }
            printf("\nDELETED ELEMENT IS %d",c->value);
            p->next=NULL;
            free(c);
            ct--;
        }
    }
}

void deletepos()
{
    int pos;

    printf("\nENTER POSITION TO DELETE  ");
    scanf("%d",&pos);

    if(pos==1)
    {
        deletefirst();
    }
    else if(pos==ct+1)
    {
        deletelast();
    }
    else if(pos<=0||pos>ct)
    {
        printf("\nINVALID POSITION!!");
    }
    else
    {
        c=first;
        p=NULL;
        for(int i=1;i<pos;i++)
        {
            p=c;
            c=c->next;
        }

        printf("\nDELETED ELEMENT IS %d",c->value);
        p->next=c->next;
        free(c);

    }

}

void search()
{
    temp=first;

    if(temp==NULL)
    {
        printf("\nLIST IS EMPTY!");
    }
    else
    {
        int data,ck=0;

        printf("\nENTER DATA TO SEARCH      ");
        scanf("%d",&data);

        do
        {
            if(data==temp->value)
            {
                printf("\nVALUE IS FOUND AT %u",temp);
                ck=1;
            }
            temp=temp->next;
        }while(temp!=last);

        if(ck==0)
        {
            printf("\nNOT FOUND!!");
        }
    }
}

void sort()
{
    temp=ma;

    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!");
    }
    else
    {
        for(c=first;c->next!=NULL;c=c->next)
        {
            for(p=c->next;p->next!=NULL;p=p->next)
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

int main()
{

    create();
    int opt;
    do
    {
        menu();
        printf("\nENTER MENU OPTION     ===>>>      ");
        scanf("%d",&opt);

        switch(opt)
        {
        case 1:
            insertfirst();
            break;
        case 2:
            insertpos();
            break;
        case 3:
            insertlast();
            break;
        case 4:
            deletefirst();
            break;
        case 5:
            deletepos();
            break;
        case 6:
            deletelast();
            break;
        case 7:
            search();
            break;
        case 8:
            sort();
            break;
        case 9:
            display();
            break;
        case 10:
            exit(0);
        default:
            printf("\nINVALID MENU OPTION!!");
        }

    }while(opt!=10);

    return 0;
}

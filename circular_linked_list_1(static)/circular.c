#include<stdio.h>
#include<stdlib.h>
#define ma (struct node*)malloc(sizeof(struct node))

struct node
{
    int value;
    struct node *next;
}*first=NULL,*last=NULL,*temp,*nn,*p,*c;

static int i=0;

void create()
{
    int x;
    printf("\nENTER [-1] TO EXIT CREATION   ");
    scanf("%d",&x);

    while(x!=-1)
    {
        i++;
        nn=ma;
        printf("\nENTER VALUE TO INSERT     ");
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
            last->next=first;
        }
        printf("\nENTER [-1] TO EXIT CREATION   ");
        scanf("%d",&x);
    }

}

void dispf()
{
    printf("\n");
    temp=first;

    if(temp==NULL)
    {
        printf("\nLIST IS EMPTY!");
    }
    else if(temp->next==first)
    {
        printf("\t%d",temp->value);
    }
    else
    {
        do
        {
            printf("\t%d",temp->value);
            temp=temp->next;
        }while(temp!=first);
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
        }while(temp!=first);

        if(ck==0)
        {
            printf("\nNOT FOUND!!");
        }
    }
}

void dispr()
{
    printf("\n");
    temp=last;

    if(temp==NULL)
    {
        printf("\nLIST IS EMPTY!");
    }
    else if(first->next==first)
    {
        printf("\t%d",temp->value);
    }
    else
    {
        do
        {
            printf("\t%d",temp->value);
            temp=temp->next;
        }while(temp!=last);
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
        for(c=first;c!=last;c=c->next)
        {
            for(p=c->next;p!=last;p=p->next)
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



void insertlast()
{
    nn=ma;

    printf("\nENTER VALUE TO INSERT     ");
    scanf("%d",&nn->value);
    nn->next=NULL;
    i++;
    if(first==NULL)
    {
        first=last=nn;
    }
    else
    {
        last->next=nn;
        last=nn;
        last->next=first;
    }
}

void insertfirst()
{
    nn=ma;
    i++;
    printf("\nENTER VALUE TO INSERT     ");
    scanf("%d",&nn->value);
    nn->next=NULL;

    if(first==NULL)
    {
        first=last=nn;
    }
    else
    {
        last->next=nn;
        nn->next=first;
        first=nn;
    }

}

void deletefirst()
{
    temp=first;

    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!!");
    }
    else if(temp->next==first)
    {
        printf("\nDELETED ELEMENT IS %d",temp->value);
        first=last=NULL;
        i--;
    }
    else
    {
        printf("\nDELETED ELEMENT IS %d",temp->value);
        first=first->next;
        last->next=first;
        free(temp);
        i--;
    }
}

void deletelast()
{
    temp=first;

    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!!");
    }
    else if(first->next==first)
    {
        i--;
        printf("\nDELETED ELEMENT IS %d",temp->value);
        first=last=NULL;
    }
    else
    {
        i--;
        for(temp=first;temp->next!=last;temp=temp->next);

        printf("\nDELETED ELEMENT IS %d",last->value);

        free(temp->next);
        temp->next=first;
        last=nn;
    }
}

void insertpos()
{
    int pos,ck=1;
    printf("\nENTER POSITION TO INSERT      ");
    scanf("%d",&pos);

    if(pos<=0||pos>i+1)
    {
        printf("\nINVALID POSITION!!");
        return;
    }


    if(pos==1)
    {
        insertfirst();
    }
    else if(pos==i+1)
    {
        insertlast();
    }
    else
    {
        nn=ma;
        printf("\nENTER VALUE TO INSERT     ");
        scanf("%d",&nn->value);
        nn->next=NULL;
        i++;
        c=first;
        p=NULL;
        while(ck<pos)
        {
            p=c;
            c=c->next;
            ck++;
        }

        nn->next=p->next;
        p->next=nn;

    }
}

void deletepos()
{
    int pos,ck=1;
    printf("\nENTER POSITION TO INSERT      ");
    scanf("%d",&pos);

    if(pos==0||pos>i+1)
    {
        printf("\nINVALID POSITION!!");
        return;
    }


    if(pos==1)
    {
        deletefirst();
    }
    else if(pos==i+1)
    {
        deletelast();
    }
    else
    {
        i--;
        c=first;
        p=NULL;
        while(ck<pos)
        {
            p=c;
            c=c->next;
            ck++;
        }
        printf("\nDELETED ELEMENT IS %d",c->value);

        p->next=c->next;
        free(c);
    }

}

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n1 - INSERT AT FIRST");
    printf("\n2 - INSERT BY POSITION");
    printf("\n3 - INSERT AT LAST");
    printf("\n4 - DELETE AT FIRST");
    printf("\n5 - DELETE BY POSITION");
    printf("\n6 - DELETE AT LAST");
    printf("\n7 - SEARCH");
    printf("\n8 - SORT");
    printf("\n9 - DISPLAY FROM FRONT");
    printf("\n10 - DISPLAY FROM LAST");
    printf("\n11 - EXIT");
}

int main()
{
    int opt;
    create();
    do
    {
        menu();
        printf("\nSELECT MENU OPTION    ===>>>      ");
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
            dispf();
            break;
        case 10:
            dispr();
            break;
        case 11:
            exit(0);
        default:
            printf("\nINVALID MENU OPTION!!");
        }

    }while(opt!=11);

    return 0;
}

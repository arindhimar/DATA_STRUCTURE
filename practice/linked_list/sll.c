#include<stdio.h>
#include<stdlib.h>
#define ma (struct node*)malloc(sizeof(struct node))

struct node
{
    int value;
    struct node *next;
}*first=NULL,*last=NULL,*nn,*temp,*p,*c;

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
    printf("\n7 - SEARCH");
    printf("\n8 - SORT");
    printf("\n9 - DISPLAY");
    printf("\n10 - EXIT");
}

void create()
{
    int x;

     printf("\n ENTER [-1] TO EXIT CREATION     ");
     scanf("%d",&x);

    while(x!=-1)
    {
        ct++;
        nn=ma;
        printf("\nENTER VALUE TO INSERT         ");
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

     printf("\n ENTER [-1] TO EXIT CREATION     ");
     scanf("%d",&x);       
    }

}

void insertlast()
{
    nn=ma;
    printf("\nENTER VALUE TO INSERT         ");
    scanf("%d",&nn->value);
    nn->next=NULL;
    ct++;
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

void insertfirst()
{
    ct++;
    nn=ma;
    printf("\nENTER VALUE TO INSERT         ");
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

void insertbypos()
{
    int pos;
    printf("\nENTER POSTION TO INSERT NODE      ");
    scanf("%d",&pos);

    if(pos<=0||pos>ct+1)
    {
        printf("\nINVALID POSITION!!");
    }
    else if(pos==1)
    {
        insertfirst();
    }
    else if(pos==ct+1)
    {
        insertlast();
    }
    else
    {
        nn=ma;
        printf("\nENTER VALUE TO INSERT         ");
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
        printf("\nLIST IS EMPTY!");
    }
    else if(first==last)
    {
        printf("\nDELETED ELEMENT IS %d",first->value);
        free(first);
        first=last=NULL;
        ct--;
    }
    else
    {
        printf("\nDELETED ELEMENT IS %d",first->value);
        temp=first;
        first=first->next;
        free(temp);
        ct--;
    }
}

void deletelast()
{
    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!");
    }
    else if(first==last)
    {
        printf("\nDELETED ELEMENT IS %d",first->value);
        free(first);
        first=last=NULL;
        ct--;
    }
    else
    {
        ct--;
        for(temp=first;temp->next!=last;temp=temp->next);

        printf("\nDELETED ELEMENT IS %d",temp->next->value);

        free(temp->next);
        last=temp;
        last->next=NULL;
    }
}

void deletebypos()
{
    int pos;
    printf("\nENTER POSTION TO DELETE NODE      ");
    scanf("%d",&pos);

    if(pos<=0||pos>ct+1)
    {
        printf("\nINVALID POSITION!!");
    }
    else if(pos==1)
    {
        deletefirst();
    }
    else if(pos==ct+1)
    {
        deletelast();
    }
    else
    {
        c=first;

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

void disp()
{
    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!");
    }
    else if(first==last)
    {
        printf("\t%d",first->value);
    }
    else
    {
        for(temp=first;temp!=NULL;temp=temp->next)
        {
            printf("\t%d",temp->value);
        }
    }
}

void search()
{
    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!");
    }
    else
    {
        int val,ck=0;
        printf("\nENTER VALUE TO SEARCH     ");
        scanf("%d",&val);
        for(temp=first;temp!=NULL;temp=temp->next)
        {
            if(val==temp->value)
            {
                printf("\nVALUE FOUND AT ADDRESS %u",temp);
                ck=1;
            }
        }
        if(ck==0)
        {
            printf("\nVALUE NOT FOUND!!");
        }
    }
}

void sort()
{
    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!!");
    }
    else
    {
        temp=ma;
        for(c=first;c!=NULL;c=c->next)
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

int main()
{
    int opt;
    create();
    do
    {
        menu();
        printf("\nSELECT MENU OPTION    ===>>>      ");
        scanf("%d",&opt);
        switch (opt)
        {
        case 1:
        insertfirst();
            break;
        case 2:
        insertbypos();
            break;
        case 3:
        insertlast();
            break;
        case 4:
        deletefirst();
            break;
        case 5:
        deletebypos();
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
        disp();
            break;
        case 10:
            exit(0);
        default:
            break;
        }
    }while(opt!=10);

    return 0;
}
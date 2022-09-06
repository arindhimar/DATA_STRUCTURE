#include<stdio.h>
#include<stdlib.h>
#define ma (struct node *)malloc(sizeof(struct node))

struct node
{
    int value;
    struct node *next;
}*first=NULL,*last=NULL,*temp,*nn,*p,*c;

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n1 - INSERT AT FIRST");
    printf("\n2 - INSERT IN BETWEEN");
    printf("\n3 - INSERT AT LAST");
    printf("\n4 - DELETE AT FIRST");
    printf("\n5 - DELETE IN BETWEEN");
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

    if(first==NULL)
    {
        printf("\nLIST IS EMPTY HENCE THIS OPERATION CAN'T BE USED!!");
    }
    else
    {
        printf("\nENTER POSITION TO ENTER       ");
        scanf("%d",&pos);

        nn=ma;
        printf("\nENTER VALUE   ");
        scanf("%d",&nn->value);
        nn->next=NULL;

        c=first;
        p=NULL;

        int i=1,ck=0;


        for(c=first;i!=pos;i++)
        {
            p=c;
            if(i!=pos&&c->next==NULL)
            {
                ck=1;
                break;
            }
            c=c->next;
        }

        if(ck==0)
        {
            nn->next=c;
            p->next=nn;
        }
        else
        {
            printf("\nINVALID POSITION!!");
        }
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
        printf("\nDELETED ELEMENT IS %d",first->value);
        free(last);
        first=last=NULL;
    }
    else
    {
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
        c=first;
        p=NULL;
        if(first->next==NULL)
        {
            printf("\nDELETED ELEMENT IS %d",c->value);
            free(last);
            printf("\nlast--f");
            first=last=NULL;
        }
        else
        {
            while(c->next!=NULL)
            {
                p=c;
                c=c->next;
            }
            printf("\nopt2");
            printf("\nDELETED ELEMENT IS %d",c->value);
            p->next=NULL;
            free(c);
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
            break;
        case 6:
            deletelast();
            break;
        case 7:
            break;
        case 8:
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

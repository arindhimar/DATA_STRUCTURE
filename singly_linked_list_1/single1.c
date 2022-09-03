#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
}*first,*last,*nn,*temp;

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n1 - INSERT FIRST");
    printf("\n2 - INSERT LAST");
    printf("\n3 - INSERT BETWEEN");
    printf("\n4 - DELETE FIRST");
    printf("\n5 - DELETE LAST");
    printf("\n6 - DELETE BETWEEN");
    printf("\n7 - DISPLAY");
    printf("\n8 - EXIT");
}

void insertfirst()
{
    nn=(struct node *)malloc(sizeof(struct node));
    printf("\nENTER VALUE TO INSERT");
    scanf("%d",&nn->value);
    if(first==NULL)
    {
         nn->next=NULL;
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
    nn=(struct node *)malloc(sizeof(struct node));
    printf("\nENTER VALUE TO INSERT");
    scanf("%d",&nn->value);
    if(first==NULL)
    {
         nn->next=NULL;
         first=last=nn;
    }
    else
    {
        nn->next=NULL;
        last->next=nn;
        last=nn;
    }
}

void insertbetween()
{
    nn=(struct node *)malloc(sizeof(struct node));
    printf("\nENTER VALUE TO INSERT");
    scanf("%d",&nn->value);
    struct node *c,*p;
    c=first;
    int pos;
    printf("ENETER POSITION TO INSERT    ");
    scanf("%d",&pos);
    int i=1;

    while(i<pos)
    {
        p=c;
        c=c->next;
        i++;
    }
    nn->next=c;
    p->next=nn;
}

void deletefirst()
{
    temp=first;
    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!!");
    }
    else
    {
        printf("\nDELETED ELEMENT IS %d",first->value);
        temp=temp->next;
        free(first);
        first=temp;
    }
}

void deletelast()
{
    struct node *c=first,*p;
    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!!");
    }
    else
    {
        printf("\nDELETED ELEMENT IS %d",last->value);
        while(c->next!=NULL)
        {
            p=c;
            c=c->next;
        }
        p->next=c->next;
        free(c);
    }
}

void deletepos()
{
    struct node *p,*c;
    c=first;
    int pos;
    if(first==NULL)
    {
        printf("\nLIST IS EMPTY!!");
    }
    else
    {
            printf("ENTER POSITION TO DELETE    ");
            scanf("%d",&pos);
            int i=1;
            while(i<pos)
            {
                p=c;
                c=c->next;
                i++;
            }
            printf("\nDELETED ELEMENT IS %d",c->value);
            p->next=c->next;
            free(c);
    }
}

void display()
{
    temp=first;
    if(temp==NULL)
    {
        printf("\nLIST IS EMPTY!");
    }
    else{
        while(temp->next!=NULL)
        {
            printf("\t%d",temp->value);
            temp=temp->next;
        }
        printf("\t%d",temp->value);
    }
}



int main()
{
    int opt;

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
        insertlast();
        break;
        case 3:
        insertbetween();
        break;
        case 4:
        deletefirst();
        break;
        case 5:
        deletelast();
        break;
        case 6:
        deletepos();
        break;
        case 7:
        display();
        break;
        case 8:
        exit(0);
        default:
            break;
        }
    } while (opt!=8);
    
    
    return 0;
}
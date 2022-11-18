#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ma (struct book*)malloc(sizeof(struct book))

int ct=0;
struct book
{
    int bid,price;
    char aname[20],title[20];
    
    struct book *next;

}*f=NULL,*l=NULL,*temp;

void menu()
{
    printf("\n1 - Create");
    printf("\n2 - Display");
    printf("\n3 - Search");
    printf("\n4 - Delete By Bid");
    printf("\n5 - Exit");
}

void create()
{
    temp=ma;
    temp->bid=++ct;
    
    printf("\nEnter Book Title          ");
    scanf("%s",temp->title);
    
    printf("\nEnter Book Author         ");
    scanf("%s",temp->aname);
    
    printf("\nEnter Book Price          ");
    scanf("%d",&temp->price);

    temp->next=NULL;

    if(f==NULL)
    {
        f=l=temp;
    }
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
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\n");
            printf("\nBID           :       %d",temp->bid);
            printf("\nBook_Author   :       %s",temp->aname);
            printf("\nBook_Name     :       %s",temp->title);
            printf("\nBook_Price    :       %d",temp->price);
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
        char atemp[20];
        int ck=0;

        printf("\nEnter Author Name to search       ");
        scanf("%s",atemp);

        for(temp=f;temp!=NULL;temp=temp->next)
        {
            if(strcmp(temp->aname,atemp)==0)
            {
                printf("\n");
                printf("\nBID           :       %d",temp->bid);
                printf("\nBook_Author   :       %s",temp->aname);
                printf("\nBook_Name     :       %s",temp->title);
                printf("\nBook_Price    :       %d",temp->price); 
                ck=1;
            }
        }

        if(ck==0)
        {
            printf("\nNo Results Found!!");
        }

    }
}

void delbybid()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        int ck=0,tbid;
        printf("\nEnter BID to Delete       ");
        scanf("%d",&tbid);

        if(f->bid==tbid&&l->bid==tbid)
        {
            temp=f;
            printf("\nDeleted Details Are   :   ");
            printf("\n");
            printf("\nBID           :       %d",temp->bid);
            printf("\nBook_Author   :       %s",temp->aname);
            printf("\nBook_Name     :       %s",temp->title);
            printf("\nBook_Price    :       %d",temp->price); 
            free(f);
            f=l=NULL;
            ck=1;
            printf("\nfl");
        }
        else if(f->bid==tbid)
        {
            temp=f;
            printf("\nDeleted Details Are   :   ");
            printf("\n");
            printf("\nBID           :       %d",temp->bid);
            printf("\nBook_Author   :       %s",temp->aname);
            printf("\nBook_Name     :       %s",temp->title);
            printf("\nBook_Price    :       %d",temp->price);           
            free(f);
            ck=1;
            f=f->next;
            free(temp);
            printf("\nf");
        }
        else if(l->bid==tbid)
        {
            temp=l;
            printf("\nDeleted Details Are   :   ");
            printf("\n");
            printf("\nBID           :       %d",temp->bid);
            printf("\nBook_Author   :       %s",temp->aname);
            printf("\nBook_Name     :       %s",temp->title);
            printf("\nBook_Price    :       %d",temp->price);           
            
            for(temp=f;temp->next!=l;temp=temp->next);
            ck=1;
            free(l);
            temp->next=NULL;
            l=temp;
            printf("\nl");
        }
        else
        {
            struct book *p,*c;
            for(c=f;c!=NULL;c=c->next)
            {
                if(c->bid==tbid)
                {
                    break;
                }
                p=c;
            }
            printf("\nDeleted Details Are   :   ");
            printf("\n");
            printf("\nBID           :       %d",c->bid);
            printf("\nBook_Author   :       %s",c->aname);
            printf("\nBook_Name     :       %s",c->title);
            printf("\nBook_Price    :       %d",c->price); 
            p->next=c->next;
            free(c);
            ck=1;
            printf("\nm");
        }

        if(ck==0)
        {
            printf("\nNo Details Found!!");
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
            disp();
            break;

            case 3:
            search();
            break;

            case 4:
            delbybid();
            break;

            case 5:
            exit(0);

            default:
            printf("\nInvalid Menu Option");
        }

    }while(opt!=5);

    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ma (struct node *)malloc(sizeof(struct node))

struct node{

    char coff[1];
    int exp;
    int x;
    struct node *next;    
    
}*first=NULL,*last=NULL,*nn,*temp,*p,*c;

void insertlast()
{
    nn=ma;
    printf("\nENTER COEFFICIENT TO INSERT     ");
    scanf("%s",&nn->coff);
    printf("\nENTER EXPONENTIAL     ");
    scanf("%d",&nn->exp);
    if(first==NULL)
    {
        nn->next=NULL;
        first=last=nn;
    }
    else
    {
        for(temp=first;temp!=last;temp=temp->next);
        temp->next=nn;
        nn->next=NULL;
        last=nn;
    }
}

void creation()
{
    int op;
    printf("\nENTER -1 TO EXIT CREATION     ");
    scanf("%d",&op);
    while(op!=-1)
    {
        insertlast();
        printf("\nENTER -1 TO EXIT CREATION     ");
        scanf("%d",&op);
    }
}

void arrange ()
{
    if(first==NULL&&last==NULL)
    {
        printf("\nEMPTY!!");
    }
    else
    {
        nn=ma;
        for(c=first;c!=NULL;c=c->next)
        {
            for(p=c->next;p!=NULL;p=p->next)
            {
                if(p->exp>c->exp)
                {
                    nn->exp=p->exp;
                    p->exp=c->exp;
                    c->exp=nn->exp;

                    strcpy(nn->coff,p->coff);
                    strcpy(p->coff,c->coff);
                    strcpy(c->coff,nn->coff);
                }
            }
        }
    }
}

void disp()
{
    if(first==NULL&&last==NULL)
    {
        printf("\nEMPTY!!");
    }  
    else
    {
        for(temp=first;temp!=NULL;temp=temp->next)
        {
            if(temp==last)
            {
               printf("%s x^%d ",temp->coff,temp->exp); 
            }
            else
            {
                printf("%s x^%d + ",temp->coff,temp->exp);
            }
        }
    }
}

void evaluate()
{
    int val;
    if(first==NULL)
    {
        printf("\nEMPTY!!");
    }
    else
    {
        printf("\nENTER VALUE FOR x     ");
        scanf("%d",&val);

        int tres=1,res=0,cofv;

        for(temp=first;temp!=NULL;temp=temp->next)
        {
            temp->x=val;
            tres=1;
            for(int i=1;i<=temp->exp;i++)
            {
                tres=tres*val;
            }
            printf("\nENTER VALUE FOR COEFFICIENT %s      ",temp->coff);
            scanf("%d",&cofv);
            res=res+(tres*cofv);
        }

        printf("\nRESULT = %d",res);

    }
}

void menu()
{
    printf("\n\tMENU PANEL");
    printf("\n1 - INSERT ");
    printf("\n2 - ARRANGE ");
    printf("\n3 - DISPLAY ");
    printf("\n4 - EVALUATE");\
    printf("\n5 - EXIT");

}

int main()
{
    int opt;
    creation();
    do
    {
        menu();
        printf("\nENTER MENU OPTION     ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            insertlast();
            break;
            case 2:
            arrange();
            break;
            case 3:
            disp();
            break;
            case 4:
            evaluate();
            break;
            case 5:
            exit(0);
            default:
            printf("\nINVALID MENU OPTION!");
        }
    } while (opt!=5);
    
    return 0;
}


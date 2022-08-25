#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};

void linkedlisttraveral(struct node *p)
{

    while(p!=NULL)
    {
        printf("\t%d",p->value);
        p=p->next;
    }
}


struct node * insertbegning(struct node *p)
{
    struct node *temp;
    printf("\nEnter value to insert ");
    scanf("%d",&temp->value);
    temp->next=p;
    return temp;
}


struct node * insertmiddle(struct node *p1,struct node *p2)
{
    struct node *temp;
    printf("\nEnter value to insert ");
    scanf("%d",&temp->value);
    p1->next=temp;
    temp->next=p2;
    return temp;
};

struct node * insertlast(struct node *p)
{
    struct node *temp;
    printf("\nEnter value to insert ");
    scanf("%d",&temp->value);
    p->next=temp;
    temp->next=NULL;
    return temp;
};


int main()
{
    struct node *ins;
    struct node *insm;
    struct node *insl;
    struct node *n1;
    struct node *n2;
    struct node *n3;


    n1=(struct node*)malloc(sizeof(struct node));
    n1->value=5;

    n2=(struct node*)malloc(sizeof(struct node));
    n1->next=n2;
    n2->value=10;

    n3=(struct node*)malloc(sizeof(struct node));
    n2->next=n3;
    n3->value=15;
    n3->next=NULL;

    linkedlisttraveral(n1);

    /*at start

    ins=insertbegning(n1);
    linkedlisttraveral(ins);*/

    /*middle
    insm=insertmiddle(n1,n2);
    linkedlisttraveral(n1);*/

    //at last
    insl=insertlast(n3);
    linkedlisttraveral(n1);



    return 0;
}


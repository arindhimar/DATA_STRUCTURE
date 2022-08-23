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

int main()
{
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


    return 0;
}

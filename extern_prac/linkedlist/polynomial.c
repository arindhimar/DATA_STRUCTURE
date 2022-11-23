/*
    Date    : 22-11-2022
    Day     : Tuesday
    Code    : Polynomial
    Author  : Arin Dhimar
*/




#include<stdio.h>
#include<stdlib.h>
#define ma (struct poly*)malloc(sizeof(struct poly))

struct poly
{
    int power,value;
    char coeff[1];
    struct poly *next;
}*f=NULL,*l=NULL,*temp;

void menu()
{
    printf("\n 1 - Create");
    printf("\n 2 - Evaluate");
    printf("\n 3 - Sort");
    printf("\n 4 - Display");
    printf("\n 5 - Exit");  
}

void create()
{
    temp=ma;
    printf("\nEnter Coefficient         ");
    scanf("%s",&temp->coeff[0]);
    // temp->value=0,temp->total=0;
    printf("\nEnter Power     ");
    scanf("%d",&temp->power);
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
        printf("\n");
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            if(temp==l)
                printf("%c*(x^%d)",temp->coeff[0],temp->power);
            else
                printf("%c*(x^%d)+",temp->coeff[0],temp->power);
        }
    }
}

void evaluate()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        int total=0,t_val,t;
        printf("\nEnter Value for 'x'   :   ");
        scanf("%d",&t_val);
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            temp->value=t_val;
            for(int i=0;i<=temp->power;i=i+1)
            {
                temp->value=temp->value*temp->value;
            }
            printf("\nEnter value for Coefficient %c    ",temp->coeff[0]);
            scanf("%d",&t);
            total=total*temp->value+t;
        }
        printf("\nEvaluation    :   %d",total);
    }
}


int main()
{
    int opt;
    do{
        menu();
        printf("\nSelect Menu Option        ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            create();
            break;
            case 2:
            evaluate();
            break;
            case 3:
            break;
            case 4:
            disp();
            break;
            case 5:
            break;
        }
    }while(opt!=5);
    return 0;
}

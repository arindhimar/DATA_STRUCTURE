#include<stdio.h>
#include<stdlib.h>
#define ma (struct employee *)malloc(sizeof(struct employee))

struct employee
{
    int eno,sal;
    char name[20];
    struct employee *next;
}*f=NULL,*l=NULL,*temp,*p,*c;

void creation()
{
    new:
    temp=ma;
    printf("\nEnter Employee Number     ");
    scanf("%d",&temp->eno);
    printf("\nEnter Employee Name       ");
    scanf("%s",temp->name);
    printf("\nEnter Employee Salary     ");
    scanf("%d",&temp->sal);
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
    int x;
    printf("\nEnter -1 to exit Creation");
    scanf("%d",&x);
    if(x!=-1)
    goto new;
    return;
}

void disp()
{
    if(f==NULL)
    {
        printf("\nList is Empty!!");
        return;
    }
    for(temp=f;temp!=NULL;temp=temp->next)
    {
        printf("\n");
        if(temp->sal>20000)
        {
            printf("\n Employee Number = %d",temp->eno);
            printf("\n Employee Name   = %s",temp->name);
            printf("\n Employee Salary = %d",temp->sal);
        }
    }
}

void del()
{
    if(f==NULL)
    {
        printf("\nList is Empty!!");
        return;
    }
    int etemp,ck=0;
    printf("\nEnter Employee Number To Delete       ");
    scanf("%d",&etemp);
    for(c=f;c!=NULL;c=c->next)
    {
        if(c->eno==etemp)
        {
            if(c==f&&f==l)
            {
                printf("\nDeleted!!");

                free(c);
                f=l=NULL;
                return;
            }
            else if(c==f)
            {
                printf("\nDeleted!!");
                p=c;
                c=c->next;
                free(p);
                f=c;
                return;
            }
            else
            {
                p->next=c->next;
                free(c);
                printf("\nDeleted!!");
                return;
            }

        }
        p=c;
    }
    printf("\nNot Found!!");


}

void menu()
{
    printf("\nMenu Panel");
    printf("\n 1 - Create");
    printf("\n 2 - Display");
    printf("\n 3 - Delete");
    printf("\n 4 - Exit");
}

int main()
{
    int opt;
    do
    {
        menu();
        printf("\nSelect Menu Option    ");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:
            creation();
            break;
            case 2:
            disp();
            break;
            case 3:
            del();
            break;
            case 4:
            exit(0);
            default:
            printf("\nINvalid Menu Option");
        }
    }while(opt!=4);
    return 0;
}
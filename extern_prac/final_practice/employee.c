/*
    Author  :   Arin Dhimar
    Date    :   25-11-2022
    Code    :   Employee Based Singly_Linked_List
*/

#include<stdio.h>
#include<stdlib.h>
#define ma (struct employee*)malloc(sizeof(struct employee))
int ct=0;
struct employee
{
    int e_no,e_salary;
    char e_name[20];
    struct employee *next;
}*f=NULL,*l=NULL,*temp;

void menu()
{
    printf("\n 1 - Create");
    printf("\n 2 - Delete");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
}

void create()
{
    temp=ma;
    temp->e_no=++ct;
    printf("\nEnter Name        ");
    scanf("%s",temp->e_name);
    printf("\nEnter Salary      ");
    scanf("%d",&temp->e_salary);
    temp->next=NULL;
    if(f==NULL)
    f=l=temp;
    else
    {
        l->next=temp;
        l=temp;
    }
}

void del()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        int opt;
        printf("\nEnter to E_NO Delete       ");
        scanf("%d",&opt);

        if(f==l&&f->e_no==opt)
        {
            printf("\nDeleted!!");
            free(f);
            f=l=NULL;
            return;
        }
        else if(f->e_no==opt)
        {
            printf("\nDeleted");
            temp=f;
            f=f->next;
            free(temp);
            return;
        }
        else if(l->e_no==opt)
        {
            printf("\nDeleted");
            for(temp=f;temp->next!=l;temp=temp->next);
            temp->next=NULL;
            free(l);
            l=temp;
            return;
        }
        else
        {
            struct employee *p,*c;
            for(c=f;c!=NULL;c=c->next)
            {
                if(c->e_no==opt)
                {
                    p->next=c->next;
                    free(c);
                    printf("\nDeleted");
                    return;

                }
                p=c;
            }
        }
        printf("\n E_NO not found!!");
    }
}

void disp()
{
    if(f==NULL)
    {
        printf("\nempty!!");
    }
    else
    {
        for(temp=f;temp!=NULL;temp=temp->next)
        {
            printf("\n E_NO     :       %d",temp->e_no);
            printf("\n E_NAME   :       %s",temp->e_name);
            printf("\n E_SALARY :       %d",temp->e_salary);
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
            del();
            break;
            case 3:
            disp();
            break;
            case 4:
            break;
        }
    }while(opt!=4);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#define ma (struct employee*)malloc(sizeof(struct employee))

struct employee{
    int emp_no,salary;
    char name[20];
    struct employee *next;
}*f=NULL,*l=NULL,*temp,*p;

void menu()
{
    printf("\nMenu Panel");
    printf("\n 1 - Insert");
    printf("\n 2 - Delete By Employee Number");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
}

void create()
{

   
    choice:
    temp=ma;
    printf("\nEnter Employee Number     :       ");
    scanf("%d",&temp->emp_no);
    printf("\nEnter Employee Name       :       ");
    scanf("%s",temp->name);
    printf("\nEnter Employee Salary     :       ");
    scanf("%d",&temp->salary);
    temp->next=NULL;

    if(f==NULL)
    {
        printf("\n1");
        f=l=temp;
    }
    else
    {
        l->next=temp;
        l=temp;
        l->next=NULL;
    }
    int x;
    printf("\nEnter -1 to exit creation     ");
    scanf("%d",&x);
    if(x!=-1)
    goto choice;

}

void del()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        int x;
        printf("\nEnter Employee Number to Delete       ");
        scanf("%d",&x);

        if(f->emp_no==x)
        {
            temp=f;
            f=f->next;
            free(temp);
        }
        else if(l->emp_no==x)
        {
            for(temp=f;temp->next!=l;temp=temp->next);

            free(l);
            l=temp;
            l->next=NULL;
        }
        else
        {
            for(temp=f;temp!=NULL;temp=temp->next)
            {
                if(temp->emp_no==x)
                {
                    p->next=temp->next;
                    free(temp);
                    return;
                }
                p=temp;
            }
        }
    }

}

void disp()
{
    if(f==NULL&&l==NULL)
    {
        printf("\nList is Empty!!");
    }
    else
    {
        
        for(temp=f;temp!=NULL;temp=temp->next)
        {

            printf("\nEmployee Number   :   %d",temp->emp_no);
            printf("\nEmployee Name     :   %s",temp->name);
            printf("\nEmployee Salary   :   %d",temp->salary);
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
            exit(0);
        }
    }while(opt!=4);
    return 0;
}
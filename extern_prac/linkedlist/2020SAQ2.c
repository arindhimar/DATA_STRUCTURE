#include<stdio.h>
#include<stdlib.h>
#define ma (struct employee*)malloc(sizeof(struct employee))

int ct=0;
struct employee
{
    int e_no;
    char e_name[20];
    float salary;
    struct employee *next;
}*f=NULL,*l=NULL,*temp;

void menu()
{
    printf("\n1 - Create");
    printf("\n2 - Display");
    printf("\n3 - Delete By emp_no");
    printf("\n4 - Exit");
}

void create()
{
    temp=ma;
    temp->e_no=++ct;
    printf("\nEnter Employee Name           ");
    scanf("%s",temp->e_name);
    printf("\nEnter Employee Salary         ");
    scanf("%f",&temp->salary);
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
            printf("\nE_NO      :   %d",temp->e_no);
            printf("\nE_NAME    :   %s",temp->e_name);
            printf("\nE_SALARY  :   %f",temp->salary);
        }
    }
}

void delbyeid()
{
    if(f==NULL)
    {
        printf("\nEmpty!!");
    }
    else
    {
        int temp_eno;
        printf("\nEnter E-no to delete      ");
        scanf("%d",&temp_eno);
        if(temp_eno>0&&temp_eno<=ct)
        {
            printf("\nDeleted Node Details:");
            if(f==l&&f->e_no==temp_eno)
            {
                temp=f;
                printf("\n");
                printf("\nE_NO      :   %d",temp->e_no);
                printf("\nE_NAME    :   %s",temp->e_name);
                printf("\nE_SALARY  :   %f",temp->salary);
                f=l=NULL;          
            }
            else if(temp_eno==f->e_no)
            {
                temp=f;
                printf("\n");
                printf("\nE_NO      :   %d",temp->e_no);
                printf("\nE_NAME    :   %s",temp->e_name);
                printf("\nE_SALARY  :   %f",temp->salary);
                f=f->next;
                free(temp);
            }
            else if (temp_eno==l->e_no)
            {
                for(temp=f;temp->next!=l;temp=temp->next);
                printf("\n");
                printf("\nE_NO      :   %d",l->e_no);
                printf("\nE_NAME    :   %s",l->e_name);
                printf("\nE_SALARY  :   %f",l->salary);
                free(l);
                l=temp;
                l->next=NULL;
            }
            else
            {
                int ck=0;
                struct employee *p,*c;
                for(c=f;c!=NULL;c=c->next)
                {
                    if(c->e_no==temp_eno)
                    {
                        ck=1;
                        break;
                    }
                    p=c;
                }

                if(ck==1)
                {
                    printf("\n");
                    printf("\nE_NO      :   %d",c->e_no);
                    printf("\nE_NAME    :   %s",c->e_name);
                    printf("\nE_SALARY  :   %f",c->salary);

                    p->next=c->next;
                    free(c);
                }
                else
                {
                    printf("\nNo Record Found!!");
                }

            }
              
        }
        else
        {
            printf("\nInvalid E_no");
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
            delbyeid();
            break;
            case 4:
            exit(0);
            break;
        }
    }while(opt!=4);
    return 0;
}
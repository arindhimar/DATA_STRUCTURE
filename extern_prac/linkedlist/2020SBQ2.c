#include<stdio.h>
#include<stdlib.h>
#define ma (struct book*)malloc(sizeof(struct book))
int ct=0;
struct book
{
    int b_no,b_price;
    char b_name[20];
    struct book *next;
}*f=NULL,*l=NULL,*temp;

void menu()
{
    printf("\n 1 - Create");
    printf("\n 2 - Delete by B_NO");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
}

void create()
{

        temp=ma;
        temp->b_no=++ct;
        printf("\nEnter Book Name       ");
        scanf("%s",&temp->b_name);
        printf("\nEnter Book Price      ");
        scanf("%d",&temp->b_price);
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
            printf("\nB_NO      :       %d",temp->b_no);
            printf("\nB_NAME    :       %s",temp->b_name);
            printf("\nB_PRICE   :       %d",temp->b_price);
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
        int temp_id;
        printf("\nEnter Book ID to delete       ");
        scanf("%d",&temp_id);
        if(temp_id>0&&temp_id<=ct)
        {
            if(f==l&&f->b_no==temp_id)
            {
                temp=f;  
                printf("\nB_NO      :       %d",temp->b_no);
                printf("\nB_NAME    :       %s",temp->b_name);
                printf("\nB_PRICE   :       %d",temp->b_price);    
                free(temp);
                f=l=NULL; 
            }
            else if(f->b_no==temp_id)
            {
                temp=f;  
                printf("\nB_NO      :       %d",temp->b_no);
                printf("\nB_NAME    :       %s",temp->b_name);
                printf("\nB_PRICE   :       %d",temp->b_price);     
                temp=f;
                f=f->next;
                free(temp);
            }
            else if(l->b_no==temp_id)
            {
                temp=l;  
                printf("\nB_NO      :       %d",temp->b_no);
                printf("\nB_NAME    :       %s",temp->b_name);
                printf("\nB_PRICE   :       %d",temp->b_price);     
                for(temp=f;temp->next!=l;temp=temp->next);
                free(l);
                temp->next=NULL;
                l=temp;
            }
            else
            {
                struct book *p,*c;
                int ck=0;
                for(c=f;c!=NULL;c=c->next)
                {
                    if(c->b_no==temp_id)
                    {
                        ck=1;
                        break;
                    }
                    p=c;
                }

                printf("\nB_NO      :       %d",c->b_no);
                printf("\nB_NAME    :       %s",c->b_name);
                printf("\nB_PRICE   :       %d",c->b_price);    
                if(ck==1)
                {
                    p->next=c->next;
                    free(c);
                }
                else
                {
                    printf("\nNo Record Found!");
                }
            }
        }
        else
        {
            printf("\nNo B_ID Found!!");
        }
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
            delbybid();
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
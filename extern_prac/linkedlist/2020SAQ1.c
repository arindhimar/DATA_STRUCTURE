#include<stdio.h>
#define size 3

int f1=-1,f2=-1,r1=-1,r2=-1;

int queue1[size],queue2[size];


void menu()
{
    printf("\n1 - Enque");
    printf("\n2 - Deque");
    printf("\n3 - Diplay");
    printf("\n4 - Exit");
}

void enque()
{
    int opt,temp;
    printf("\nEnter 1 to insert to 'QA' ,  0 to insert to 'QB'");
    scanf("%d",&opt);

    if(opt==1)
    {
        if(r1==size-1)
        {
            printf("\nQA is full!!");
        }
        else
        {
            printf("\nEnter value to insert     ");
            scanf("%d",&temp);
            if(f1==-1&&r1==-1)
            {
                f1=0,r1=0;
                queue1[r1]=temp;
            }
            else
            {
                queue1[++r1]=temp;
            }
        }
    }else if(opt==0)
    {
        if(r2==size-1)
        {
            printf("\nQB is full!!");
        }
        else
        {
            printf("\nEnter value to insert     ");
            scanf("%d",&temp);
            if(f2==-1&&r2==-1)
            {
                f2=0,r2=0;
                queue2[r2]=temp;
            }
            else
            {
                queue2[++r2]=temp;
            }
        }
    }
    else
    printf("\nInvalid Enque option");

}

void deque()
{
    if(f2==-1&&f1==-1)
    {
        printf("Both queue are empty!!");
    }
    else
    {
        if(f1!=-1)
        {
            printf("\nDequed Element is %d",queue1[f1]);
            if(f1==r1)
            {
                f1=r1=-1;
            }
            else
            {
                f1++;
            }
        }
        else
        {
            printf("\nDequed Element is %d",queue2[f2]);
            if(f2==r2)
            {
                f2=r2=-1;
            }
            else
            {
                f2++;
            }        
        }
    }
}

void disp()
{
    printf("\n");
    for(int i=f2;i<=r2;i++)
    {
        printf("\t%d",queue2[i]);
    }
    for(int i=f1;i<=r1;i++)
    {
        printf("\t%d",queue1[i]);
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
            enque();
            break;
            case 2:
            deque();
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
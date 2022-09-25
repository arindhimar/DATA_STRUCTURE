#include<stdio.h>
#include<stdlib.h>
#define N 4
#define S 3

char a[N],b[S],ch[1];
int f1,r1,f2,r2;
f1=-1,r1=-1,f2=-1,r2=-1;

void menu()
{
    printf("\nMenu Panel");
    printf("\n 1 - Enque");
    printf("\n 2 - Deque");
    printf("\n 3 - Display");
    printf("\n 4 - Exit");
}

void enque()
{
    if(r1==N-1&&r2==S-1)
    {
        printf("\nBoth Queue are full!!");
        return;
    }
    printf("\nEnter char to push    ");
    scanf("%s",ch);
    int mopt;
    do
    {
        printf("\n1 - Push to Queue A");
        printf("\n2 - Push to Queue B");
        printf("\n3 - Cancel Push");
        scanf("%d",&mopt);
        switch(mopt)
        {
            case 1:
            if(r1==N-1)
            {
                printf("\nQueue A is full!!");
                return;
            }

            if(f1==-1)
            {
                f1=r1=0;
                a[f1]=ch[0];
            }
            else
            {
                a[++r1]=ch[0];
            }
            return;
            
            break;
            case 2:

            if(r2==S-1)
            {
                printf("\nQueue B is full!!");
                return;
            }

            if(f2==-1)
            {
                f2=r2=0;
                b[f2]=ch[0];
            }
            else
            {
                b[++r2]=ch[0];
            }
            return;

            break;
            case 3:
            break;
            default:
            printf("\nInvalid Enque option");
        }
    }while(mopt!=3);

}

void disp()
{
    if(f1==-1&&f2==-1)
    {
        printf("\nBoth Queue are Empty!!");
        return;
    }
    printf("\nQueue A :");
    for(int i=f1;i<=r1;i++)
    {
        printf("\t%c",a[i]);
    }

    printf("\nQueue B :");
    for(int i=f2;i<=r2;i++)
    {
        printf("\t%c",b[i]);
    }
}

void deque()
{
    if(f1==-1&&f2==-1)
    {
        printf("\nBoth Queue are Empty!!");
        return;
    }   
    if(f1!=-1)
    {
        if(f1==r1)
        {
            printf("\nChar popped is %c",a[f1]);
            f1=r1=-1;
        }
        else
        {
            printf("\nChar popped is %c",a[f1]);
            f1++;
        }
    }
    else
    {
        if(f2==r2)
        {
            printf("\nChar popped is %c",b[f2]);
            f2=r2=-1;
        }
        else
        {
            printf("\nChar popped is %c",b[f2]);
            f2++;
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
            enque();
            break;
            case 2:
            deque();
            break;
            case 3:
            disp();
            break;
            case 4:
            exit(0);
            default:
            printf("\nInvalid Menu Option");
        }
    }while(opt!=4);
    return 0;
}
 #include<stdio.h>
 #define N 3

int cq[N],f,r;
f=-1;
r=-1;

void menu()
{
    printf("\nMenu Panel");
    printf("\n1 - Enque");
    printf("\n2 - Deque");
    printf("\n3 - Display");
    printf("\n4 - Exit");
}

void enque()
{
    if((r+1)%N==f)
    {
        printf("\nFull!!");
    }
    else
    {
        if(f==-1)
            f=r=0;
        else
            r=(r+1)%N;

        printf("\nEnter value to insert     ");
        scanf("%d",&cq[r]);
    }
}

void disp()
{
    if(f==-1)
    {
        printf("\nEmpty!");
    }
    else
    {
        if(f<=r)
        {
            for(int i=f;i<=r;i++)
            {
                printf("\t%d",cq[i]);
            }
        }
        else
        {
            for(int i=f;i<N;i++)
            {
                printf("\t%d",cq[i]);
            }
            for(int i=0;i<=r;i++)
            {
                printf("\t%d",cq[i]);
            }
        }
    }
}

void deque()
{
    if(f==-1)
    {
        printf("\nEmpty!!");
    }
    else
    {
        printf("\nDeleted value is %d",cq[f]);
        if(f==r)
        {
            f=r=-1;
        }
        else
        {
            f=(f+1)%N;
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
            break;
            default:
            printf("\nInvalid Menu option!!");
        }

    }while(opt!=4);
    return 0;
}
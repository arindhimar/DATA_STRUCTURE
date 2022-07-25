#include<stdio.h>
int main()
{
    int n;
    printf("\nENTER SIZE        ");
    scanf("%d",&n);
    int a[n],*p,i,j,temp;

    p=a;

    for(i=0;i<n;i++)
    {
        printf("\nENTETR VALUE FOR ELEMENT %d       ",i+1);
        scanf("%d",&*(p+i));
    }

    printf("\nARRAY    :    ");

    for(i=0;i<n;i++)
    {
        printf("\t%d",*(p+i));
    }



    int pos,val,k;


    do
    {
        printf("\nENTER POSITION TO INSERT      ");
        scanf("%d",&pos);
        if(pos>0&&pos<=n)
        {
            k=1;
        }
    }while(k!=1);


    for(i=n;i>=pos-1;i--)
    {
        *(p+i+1)=*(p+i);
    }


    printf("\nENTER VALUE TO INSERT             ");
    scanf("%d",&val);

    *(p+pos-1)=val;




    printf("\nARRAY :   ");
    for(i=0;i<=n;i++)
    {
        printf("\t%d",*(p+i));
    }




    do
    {
        printf("\nENTER POSITION TO DELETE      ");
        scanf("%d",&pos);
        if(pos>0&&pos<=n)
        {
            k=0;
        }
    }while(k!=0);


    for(i=pos;i<=n;i++)
    {
        *(p+i-1)=*(p+i);
    }
    printf("\nARRAY :   ");
    for(i=0;i<n;i++)
    {
        printf("\t%d",*(p+i));
    }


    return 0;
}

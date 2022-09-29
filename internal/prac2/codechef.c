#include<stdio.h>

int main()
{
    int t,x;

    printf(" ");
    scanf("%d",&t);

    int a[10][10],c[10],n;

    int i,j,k,ct=0;

    for(k=0;k<t;k++)
    {
        printf(" ");
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            
            printf("%d",&x);
            for(j=0;j<ct;j++)
            {
                if(x==a[j][0])
                {
                    a[j][1]=a[j][1]+1;
                    break;
                }
            }

            ct=ct+1;

        }
    }

    

    return 0;
}
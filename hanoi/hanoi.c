/*
this code is written by arin_dhimar
date:31/08/2022
*/

#include<stdio.h>

void hanoi(int n,char from,char to,char temp)
{
    if(n==1)
    {
        printf("\nMOVE %d disc from %c to %c",n,from,to);
        return;
    }
    hanoi(n-1,from,temp,to);//CALLED FOR A SINGLE TOWER
    printf("\nMOVE %d disc from %c to %c",n,from,to);
    hanoi(n-1,temp,to,from);//CALLED FOR A SINGLE TOWER
    //HENCE NEED TO BE CALLED TWICE
}

int main()
{
    int no;
    printf("\nENTER NUMBER OF DISCS         ");
    scanf("%d",&no);
    hanoi(no,'A','C','B');
    return 0;
}

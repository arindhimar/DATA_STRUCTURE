/*
    Date    : 22-11-2022
    Day     : Tuesday
    Code    : Temp
    Author  : Arin Dhimar
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int bookno;
    int price;
    char bookname[100];
    struct node *next;
} * head;

void insert(int bookno, int price, char *bookname);
void search(int price);
void delete (int bookno);
void display();

void insert(int bookno, int price, char *bookname)
{
    struct node *book = (struct node *)malloc(sizeof(struct node));
    book->bookno = bookno;
    book->price = price;
    strcpy(book->bookname, bookname);

    book->next = NULL;
    if (head == NULL)
    {
        // if head is NULL
        // set student as the new head
        head = book;
    }
    else
    {
        // if list is not empty
        // insert student in beginning of head
        struct node *temp;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=book;
    }
}


void search(int price)
{
    struct node *temp = head;

    while (temp != NULL)
    {
        if (temp->price <= price)
        {
            printf("\n Book No. is %d", temp->bookno);
            printf("\n Book Price is %d", temp->price);
            printf("\n Book Name is %s", temp->bookname);
        }
        temp = temp->next;
    }
}

void delete (int bookno)
{
    struct node *temp1 = head;
    struct node *temp2 = head;

    while (temp1 != NULL)
    {
        if (temp1->bookno == bookno)
        {
            if (temp1 == temp2)
            {
                head = head->next;
                free(temp1);
            }
            else
            {
                temp2->next = temp1->next;
                free(temp1);
                return;
            }
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("\n Book No. is %d", temp->bookno);
        printf("\n Book Price is %d", temp->price);
        printf("\n Book Name is %s", temp->bookname);

        temp = temp->next;
    }
}

int main()
{
    int ch;
    int bookno;
    int price;
    char bookname[100];

    do
    {
        printf("\n*****BOOK LONKED LIST****\n");
        printf("\n (01) Creation of Book LL              \n");
        printf("\n (02) Search Book Price less than 500  \n");
        printf("\n (03) Delete By Bookno                 \n");
        printf("\n (04) Display                          \n");
        printf("\n (05) Exit                             \n");
        printf("\n***************\n");

        printf("\n Enter Your Choice : \n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\n Enter Book No. : \n");
            scanf("%d", &bookno);

            printf("\n Enter Book Name : \n");
            scanf("%s", bookname);

            printf("\n Enter Book Price : \n");
            scanf("%d", &price);

            insert(bookno, price , bookname);
            break;

        case 2:
            printf("\n Enter The price to search \n");
            scanf("%d", &price);
            search(price);
            break;

        case 3:
            printf("\n Enter Bookno to delete Details : \n");
            scanf("%d", &bookno);
            delete (bookno);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;

        default:
            printf("\n Invalid Choice \n");
            break;
        }

    } while (ch != 0);

    return 0;
}
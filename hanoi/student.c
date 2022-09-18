
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int rno;
	char name[20],div[1];
	float total;
	struct node *next;
}*first=NULL,*last=NULL,*nn,*temp,*c,*p;

int tot;

void menu()
{
	printf("\n\tMENU PANEL");
	printf("\n1 - DELETE BY ROLL NO");
	printf("\n2 - DISPLAY HIGHEST SCORER");
	printf("\n3 - DISPLAY ");
	printf("\n4 - EXIT");
}

void create()
{
	int x;

	printf("\nENTER (-1) TO END		");
	scanf("%d",&x);



	while(x!=-1)
	{
		tot++;
		nn=(struct node*)malloc(sizeof(struct node));
		printf("\nENTER RNO			");
		scanf("%d",&nn->rno);

		printf("\nENTER NAME			");
		scanf("%s",&nn->name);

		printf("\nENTER DIVISION			");
		scanf("%s",&nn->div);

		printf("\nENTER TOTAL			");
		scanf("%f",&nn->total);

		nn->next=NULL;

		if(first==NULL)
		{
			first=last=nn;
		}
		else
		{
			last->next=nn;
			last=nn;
		}

		printf("\nENTER (-1) TO END		");
		scanf("%d",&x);
	}
}
/*
void deletefirst()
{
	temp=(struct node *)malloc(sizeof(struct node));
	if(first==NULL)
	{
		printf("\nLINKED LIST IS EMPTY!!");
	}
	else
	{
		temp=first;
		printf("\nDELETED RECORD RNO IS %d",temp->rno);
		printf("\nDELETED RECORD NAME IS %s",temp->name);
		printf("\nDELETED RECORD TOTAL IS %f",temp->total);
		first=first->next;
		free(temp);
	}
}

void deletelast()
{
	if(first==NULL)
	{
		printf("\nLINKED LIST IS EMPTY!!");
	}
	else
	{
		c=first;
		p=NULL;

		while(c->next!=NULL)
		{
			p=c;
			c=c->next;
		}
		printf("\nDELETED RECORD RNO IS %d",temp->rno);
		printf("\nDELETED RECORD NAME IS %s",temp->name);
		printf("\nDELETED RECORD TOTAL IS %f",temp->total);

		free(c);
		last=p;

		last->next=NULL;

//		free(last);
//		last=temp;


	}
}

void deletepos()
{
	temp=(struct node *)malloc(sizeof(struct node));
	int pos;
	printf("\nENTER POSITION TO DELETE");
	scanf("%d",&pos);

	struct node *c,*p;

	c=first;

	int i=1;
	while(i<pos)
	{
		p=c;

		c=c->next;

		i++;
	}
	printf("\nDELETED RECORD RNO IS %d",temp->rno);
	printf("\nDELETED RECORD NAME IS %s",temp->name);
	printf("\nDELETED RECORD TOTAL IS %f",temp->total);

	if(c==last)
	{
		free(c);
		last=p;

		last->next=NULL;
	}
	else
	{
		p->next=c->next;
	}

}*/

void deleteroll()
{
    if(first==NULL)
    {
        printf("\nEmpty!!");
        return;
    }

//	temp=(struct node *)malloc(sizeof(struct node));
	int pos,ck=0;
	printf("\nENTER ROLL NO TO DELETE");
	scanf("%d",&pos);

	if(pos==first->rno)
	{
		c=first;

		printf("\nRNO IS %d",first->rno);
		printf("\nDIV IS %s",first->div);
		printf("\nNAME IS %s",first->name);
		printf("\nTOTAL IS %f",first->total);
		first=first->next;
		free(c);
	}
	else if(pos==last->rno)
	{
		temp=last;
		printf("\nRNO IS %d",temp->rno);
		printf("\nDIV IS %s",temp->div);
		printf("\nNAME IS %s",temp->name);
		printf("\nTOTAL IS %f",temp->total);
		for(temp=first;temp!=last;temp=temp->next);
		free(temp->next);
		last=temp;
		last->next=NULL;
	}
	else
	{
		for(c=first;c!=NULL;c=c->next)
		{

			if(pos==c->rno)
			{
                ck=1;
                break;
			}

			p=c;
		}
        if(ck==0)
        return;

		printf("\nRNO IS %d",c->rno);
		printf("\nDIV IS %s",c->div);
		printf("\nNAME IS %s",c->name);
		printf("\nTOTAL IS %f",c->total);
		p->next=c->next;
		free(c);
	}


}

void topper()
{
    if(first==NULL)
    {
        printf("\nEmpty");
        return;
    }
	int tempm=0;
	for(p=first;p!=NULL;p=p->next)
	{
		if(p->total>tempm)
		{
			temp=p;
			tempm=temp->total;
		}
	}

	printf("\nTOPPER DETAILS	:	");
	printf("\nRNO IS %d",temp->rno);
	printf("\nDIV IS %s",temp->div);
	printf("\nNAME IS %s",temp->name);
	printf("\nTOTAL IS %f",temp->total);


}
/*
void search()
{
	int ch=0;
	printf("\nENTER RNO TO SERACH		");
	scanf("%d",&x);

	temp=first;

	while(temp->next!=NULL)
	{
		if(temp->rno==x)
		{
			ch=1;
			break;
		}
		temp=temp->next;
	}

	if(ch==1)
	{
		printf("\nRNO is present at %u",temp);
	}
	else
	{
		printf("\nRNO not found!!");
	}

}*/

void transverse()
{

	temp=first;
	if(first==NULL)
	{
		printf("\nEMPTY!");
	}
	else
	{
		for(temp=first;temp!=NULL;temp=temp->next)
		{
			printf("\nRNO IS %d",temp->rno);
			printf("\nDIV IS %s",temp->div);
			printf("\nNAME IS %s",temp->name);
			printf("\nTOTAL IS %f",temp->total);
			printf("\n\n");
		}
	}


}
/*
void insertfirst()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("\nENTER RNO			");
	scanf("%d",&nn->rno);
	printf("\nENTER NAME			");
	scanf("%s",&nn->name);

	printf("\nENTER TOTAL			");
	scanf("%f",&nn->total);
	nn->next=NULL;

	if(first==NULL)
	{
		first=nn;
		last=nn;
	}
	else
	{
		nn->next=first;
		first=nn;
	}

}

void insertlast()
{
	nn=(struct node*)malloc(sizeof(struct node));
	printf("\nENTER RNO			");
	scanf("%d",&nn->rno);
	printf("\nENTER NAME			");
	scanf("%s",&nn->name);

	printf("\nENTER TOTAL			");
	scanf("%f",&nn->total);
	nn->next=NULL;

	if(first==NULL)
	{
		first=nn;
		last=nn;
	}
	else
	{
		last->next=nn;
		last=nn;
	}

}

void insertpos()
{
	int pos;

	printf("\nENTER POSITION TO ENTER		");
	scanf("%d",&pos);

	nn=(struct node *)malloc(sizeof(struct node));
	printf("\nENTER RNO			");
	scanf("%d",&nn->rno);
	printf("\nENTER NAME			");
	scanf("%s",&nn->name);

	printf("\nENTER TOTAL			");
	scanf("%f",&nn->total);
	int i=1;

	c=first;

	while(i<pos)
	{
		p=c;
		c=c->next;

		i++;
	}

	//SINGLE NODE POINTER METHOD
	nn->next=p->next;
	p->next=nn;

	//DOUBLE NODE POINTER METHOD
	nn->next=c;
	p->next=nn;
}*/

int main()
{

	create();
	int mopt;

	do
	{
		menu();
		printf("\nSELECT MENU OPTION	===>>>	");
		scanf("%d",&mopt);
		switch(mopt)
		{
		case 1:
			deleteroll();
			break;
		case 2:
			topper();
			break;
		case 3:
			transverse();
			break;
		case 4:
			exit(0);

		default:
			printf("\nINVALID MENU OPTION");
		}
	}while(mopt!=4);


	return 0;
}
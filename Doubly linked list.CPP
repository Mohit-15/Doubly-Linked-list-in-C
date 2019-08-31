#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

void display();
void insert_b();
void insert_e();
void insert_at_parti();
void insert_in_sorted();
void delete_b();
void delete_e();
void delete_at_parti();

struct node
{
	int info;
	struct node *lpt,*rpt;
};
struct node *first,*ptr,*cpt,*tpt;

int main()
{
	int c;
	char ch;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter first node info: ");
	scanf("%d",&ptr->info);
	first=ptr;
	do
	{
		cpt=(struct node*)malloc(sizeof(struct node));
		printf("Enter next node info: ");
		scanf("%d",&cpt->info);
		ptr->rpt=cpt;
		cpt->lpt=ptr;
		ptr=cpt;
		printf("You want to add More node?: ");
		scanf(" %c",&ch);
	}while(ch=='y' || ch=='Y');
	ptr->rpt=NULL;
	first->lpt=NULL;
	display();
	while(1)
	{
	printf("1.Insert at begin! \n");
	printf("2.Insert at end! \n");
	printf("3.Insert at given node! \n");
	printf("4.Insert at sorted list! \n");
	printf("5.Deletion of first node! \n");
	printf("6.Deletion of end! \n");
	printf("7.Deletion of particular node! \n");
	printf("Enter your choice: ");
	scanf("%d",&c);
	switch(c)
	{
		case 1: insert_b();
		        break;
        case 2: insert_e();
                break;
        case 3: insert_at_parti();
                break;
        case 4: insert_in_sorted();
                break;
        case 5: delete_b();
                break;
        case 6: delete_e();
                break;
        case 7: delete_at_parti();
                break;
       default: printf("invalid!! \n");
                break;
	}
	return 0;
}
}

void display()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr=first;
	while(ptr!=NULL)
	{
		printf("%d->",ptr->info);
		ptr=ptr->rpt;
	}
	printf("\n");
}

void insert_b()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter data you want to add: ");
	scanf("%d",&ptr->info);
	ptr->rpt=first;
	first->lpt=ptr;
	first=ptr;
	ptr->lpt=NULL;
	display();
}

void insert_e()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter data you want to add at end: ");
	scanf("%d",&ptr->info);
	cpt=first;
	while(cpt->rpt!=NULL)
	{
		cpt=cpt->rpt;
	}
	cpt->rpt=ptr;
	ptr->lpt=cpt;
	ptr->rpt=NULL;
	display();
}

void insert_at_parti()
{
	int data;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter data you want to add: ");
	scanf("%d",&ptr->info);
	printf("Enter data you want to add after node: ");
	scanf("%d",&data);
	cpt=first;
	while(cpt->info!=data)
	{
		cpt=cpt->rpt;
	}
	tpt=cpt->rpt;
	ptr->rpt=tpt;
	tpt->lpt=ptr;
	cpt->rpt=ptr;
	ptr->lpt=cpt;
	display();
}

void insert_in_sorted()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter data you want to add: ");
	scanf("%d",&ptr->info);
	cpt=first;
	while(cpt->info<ptr->info)
	{
		cpt=cpt->rpt;
	}
	tpt=cpt->lpt;
	ptr->rpt=cpt;
	cpt->lpt=ptr;
	tpt->rpt=ptr;
	ptr->lpt=tpt;
	display();
}

void delete_b()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(first==NULL)
         printf("underflow and stopped!!");
    else
	{
		ptr=first;
		first=ptr->rpt;
		first->lpt=NULL;
		ptr->rpt=cpt;
		cpt=ptr;
		display();
	}     
}

void delete_e()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	ptr=first;
	while(ptr->rpt!=NULL)
	{
		ptr=ptr->rpt;
	}
	cpt=ptr->lpt;
	cpt->rpt=NULL;
	display();
	
}

void delete_at_parti()
{
	int data;
	ptr=(struct node*)malloc(sizeof(struct node));
	printf("Enter data you want to delete: ");
	scanf("%d",&data);
	ptr=first;
	while(ptr->info!=data)
	{
		ptr=ptr->rpt;
	}
	cpt=ptr->lpt;
	cpt->rpt=tpt;
	tpt->lpt=cpt;
	display();
}

#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};

typedef struct node node;
node *head;

//*************************insert front******************************

void insert_front()
{
	int data;
	node *temp;
	
	printf("\nEnter data to insert : ");
	scanf("%d",&data);
	
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
		
	if(head == NULL)
	{
		head=temp;
		head->next=NULL;
	}
	else
	{
		temp->next=head;
		head=temp;
	}
}



//*************************insert end******************************

void insert_end()
{
	int data;
	node *temp,*pre;
	
	printf("\nEnter data to insert: ");
	scanf("%d",&data);
	
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	
	if(head == NULL)
	{
		head=temp;
		head->next=NULL;
	}
	else
	{
		pre=head;
		while(pre->next != NULL)
		{
			pre=pre->next;
		}
		pre->next=temp;
		temp->next=NULL;
	}	
}

//*************************insert position******************************

void insert_pos()
{
	int data;
	int pos;
	int count=2;
	node *temp,*pre;
	
	printf("\nEnter data to insert : ");
	scanf("%d",&data);
	printf("\nEnter Position to insert : ");
	scanf("%d",&pos);
	
	temp=head;
	pre=(node*)malloc(sizeof(node));
	pre->data=data;
	
	if(head == NULL)
	{
		printf("\nList is Empty \n");
	}
	else if(pos == 1)
	{
			pre->next=head;
			head=pre;
	}
	else
	{
		temp=head;
		while(temp->next != NULL)
		{
		if(pos==count)
		{
			pre->next=temp->next;
			temp->next=pre;
			break;
		}
		else{
			temp=temp->next;
			count++;
		}
	    }
	}
}

//*************************display******************************

void display()
{
	node *temp;
	int count=1;
	temp=head;
	if(head == NULL)
	{
		printf("\nList is Empty \n");
	}
	else{
	while(temp->next != NULL)
	{
		printf("List [%d] : %d\n",count,temp->data);
		temp=temp->next;
		count++;
	}
	printf("List [%d] : %d\n",count,temp->data);
    }
}

//*************************search******************************

void search()
{
	node *temp;
	int flag=0;
	int count=1;
	temp=head;
	int data;
	printf("Enter element to search : ");
	scanf("%d",&data);
	
	if(head == NULL)
	{
		printf("\nList is Empty \n");
	}
	else{
	while(temp->next != NULL)
	{
		if(data == temp->data)
		{
			flag=1;
			break;
		}
		temp=temp->next;
		count++;
	}
	if(temp->data == data)
	{
		flag=1;
	}
	if(flag==1)
	{
	printf("\nFound\n");
	}
	else{
		printf("\nnot found\n");
	}
}
}

int main()
{
	int ch;
	printf("\t************MENU**************\n");
	printf("\t1. Insertion at front\n");
	printf("\t2. Insertion at end\n");
	printf("\t3. Insertion at Position\n");
	printf("\t4. Display\n");
	printf("\t5. Search\n");
	printf("\t6. Quit\n");
	printf("\t*****************************\n");
	do
	{
	printf("\nEnter your Choice : ");
	scanf("%d",&ch);
	
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_end();
				break;
			case 3:
				insert_pos();
				break;
			case 4:
				display();
				break;
			case 5:
				search();
				break;
			case 6:
				break;
			default:
				printf("Invalid Choice");
		}
	}while(ch!=6);
	return 0;
}



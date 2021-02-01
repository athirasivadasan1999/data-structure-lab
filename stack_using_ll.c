#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
	int data;
	struct node *next;
};

typedef struct node node;
node *head;


void push()
{
int data;
	node *temp,*pre;
	
	printf("\nEnter value : ");
	scanf("%d",&data);
	
	temp=(node*)malloc(sizeof(node));
	temp->data=data;
	
	if(head == NULL)
	{
		head=temp;
		head->next=NULL;
	}
	else{
		pre=head;
		while(pre->next != NULL)
		{
			pre=pre->next;
		}
		pre->next=temp;
		temp->next=NULL;
	}	
}


void pop()
{
	node *temp;
	temp=head;
	if(head == NULL)
	{
		printf("\nStack is Empty \n");
	}
	else{
		while(temp->next->next != NULL)
		{
		temp=temp->next;
	    	}
	temp->next=NULL;
	}
}


void peek()
{
	node *temp;
	int count=1;
	temp=head;
	if(head == NULL)
	{
		printf("\nStack is Empty \n");
	}
	else{
	while(temp->next != NULL)
	{
		temp=temp->next;
		count++;
	}
	printf("Stack [%d] : %d\n",count,temp->data);
    	}        
}


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

int main()
{
	int ch;
	printf("\t************MENU*************\n");
	printf("\t1. PUSH\n");
	printf("\t2. POP\n");
	printf("\t3. PEEK\n");
	printf("\t4. DISPLAY\n");
	printf("\t5. QUIT\n");
	printf("\t*****************************\n");
	do
	{
	    printf("choose your option : ");
	    scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				break;
			default:
			    printf("\nInvalid Choice \n");
		}
	}while(ch!=5);
	return 0;
}



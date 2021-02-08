#include <stdio.h>
#include<stdlib.h>

struct node
{
	int n;
	struct node *prev;	
	struct node *next;
}*h,*temp,*temp1,*temp2,*temp3,*temp4,*ptr;

void insert_beg();
void insert_end();
void insert_pos();
void display_beg(int);
void display_end();
void delete_beg();
void delete_end();
void delete_pos();
void search();
int count=0;

void main()
{
	int ch;
	h= NULL;
	temp = temp1=NULL;
	printf("\nChoose:\n1. Insert at begining\n2. Insert at end\n3. Insert at  position\n4. Delete from begining\n5. Delete from end\n6. Delete from position\n7. Display from end\n8. Display from beginning\n9. Search\n10. End \n");
    
while(1)
{
	printf("\nenter your choice ");
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:	insert_beg();
        	break;

	case 2:	insert_end();
        	break;

	case 3:insert_pos();
        	break;

	case 4:delete_beg();
        	break;

	case 5:delete_end();
        	break;

	case 6:	delete_pos();
		break;

	case 7:display_end();
        	break;

	case 8:	temp2=h;
        	if(temp2==NULL)
		{
			printf("\n List is empty");
		}
		else
		{
			printf("\n elements of the List : ");
			display_beg(temp->n);
		}
        	break;
	
	case 9: search();
        	break;

	case 10: exit(0);
	        break;
	
	default:printf("\nWrong Choice");
    }
  }
}

void create()
{
	int data;
	temp = (struct node*)malloc(1*sizeof(struct node));
	temp->prev=NULL;
	temp->next=NULL;
	printf("\n enter value to insert: ");
	scanf("%d",&data);
	temp->n=data;
	count++;
}


void insert_beg()
{
	if(h==NULL)
	{
		create();
		h=temp;
		temp1=h;
	}
	else
	{
		create();
		temp->next=h;
		h->prev=temp;
		h=temp;
	}
}


void insert_end()
{
	if(h==NULL)
	{
		create();
		h=temp;
		temp1=h;
	}
	else
	{
		create();
		temp1->next=temp;
		temp->prev=temp1;
		temp1=temp;
	}
}

void insert_pos()
{
	int pos,i=2;
	printf("\nEnter position to insert: ");
	scanf("%d",&pos);
	temp2=h;
	if((pos<1)||(pos>=count+1))
	{
		printf("\nposition out of range");
		return;
	}
	if((h==NULL)&&(pos!=1))
	{
		printf("\nempty list");
		return;
	}
	if((h==NULL)&&(pos=1))
	{
		create();
		h=temp;
		temp1=h;
		return;
	}
	else
	{
		while(i<pos)
		{
			temp2=temp->next;
			i++;
		}
	create();
	temp->prev=temp2;
	temp->next=temp2->next;
	temp2->next->prev=temp;
	temp2->next=temp;
	}
}

void delete_beg()
{
	if(h==NULL)
	{
		printf("\nempty list");
		return;
	}
	else
	{
		temp=h;
		h=h->next;
		h->prev=NULL;
		printf("\ndeleted element is %d ", temp->n);
		free(temp);
	}
}

void delete_end()
{
	if(h==NULL)
	{
		printf("\nempty list");
		exit(0);
	}
	else if(h->next==NULL)
	{
		temp=h;
		h=NULL;
		printf("\ndeleted element is %d ", temp->n);
		free(temp);
	}	
	else
	{
	ptr=h;
	while(ptr->next!=NULL)
	{
		temp=ptr;
		ptr=ptr->next;
	}
	temp1=temp->next;
	printf("\ndeleted element is %d ", temp->n);
	temp->next=NULL;
	free(temp1);
	}
}

void delete_pos()
{
	int i=1,pos;
	printf("\nenter position to delete ");
	scanf("%d",&pos);
	temp2=h;
	if((pos<1)||(pos>=count+1))
	{
		printf("\nposition out of range");
		return;
	}
	if(h==NULL)
	{
		printf("\nempty list");
		return;
	}
	else
	{
	while(i<pos)
	{
		temp2=temp2->next;
		i++;
	}
	if(i==1)
	{
		if(temp2->next==NULL)
		{
			printf("\nNode deleted");
			free(temp2);
			temp2=h=NULL;
			return;
		}
	}
	if(temp2->next==NULL)
	{
		temp2->prev->next=NULL;
		free(temp2);
		printf("\nNode deleted");
		return;
	}
	temp2->next->prev=temp2->prev;
	if(i!=1)
	{
		temp2->prev->next=temp2->next;
	}
	if(i==1)
	{
		h=temp2->next;
	}
	printf("\nNode deleted");
	free(temp2);
	}
	count--;
}

void display_end()
	{
	temp2=h;
	if(temp2==NULL)
	{
		printf("\nempty list");
		return;
	}
	printf("\nelements from end: ");
	while(temp2->next!=NULL)
	{
		printf("%d\t",temp2->n);
		temp2=temp2->next;
	}
	printf("%d\t",temp2->n);
}


void display_beg(int i)
{
	if(temp2!=NULL)
	{
		i=temp2->n;
		temp2=temp2->next;
		display_beg(i);
		printf("%d\t",i);
	}
}

void search()
{
	int data,count=0;
	temp2=h;
	if(temp2==NULL)
	{
		printf("\nempty list");
		return;
	}
	printf("Enter value to search: ");
	scanf("%d",&data);
	while(temp2!=NULL)
	{
		if(temp2->n == data)	
		{
			printf("Data found at %d postion ",count+1);
			return;
		}
		else
		{
			temp2=temp2->next;
			count++;
		}
	}
	printf("\nData not found");
}


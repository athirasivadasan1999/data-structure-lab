#include<stdio.h>
#define MAX 5
int cq[MAX];
int front = -1;
int rear = -1;
void insert();
void deletion();
void display();

int main()
{
	int ch,item;
	printf("********* CIRCULAR QUEUE OPERATIONS*********");
	printf("\n\t1.INSERTION");
	printf("\n\t2.DELETION");
	printf("\n\t3.DISPLAY");
	printf("\n\t4.QUIT");
	printf("\n******************************************");
	do
	{
	    printf("\nEnter your choice : ");
	    scanf("%d",&ch);
	    switch(ch)
		{
		case 1 :
			printf("\nInput the element for insertion in queue : ");
			scanf("%d", &item);
			insert(item);
			break;
		case 2 :
			deletion();
			break;
		case 3:
			display();
			break;
		case 4:
			break;
		default:
			printf("invalid choice");
		}
	}while(ch!=4);
	return 0;
}

void insert(int item)
{
	if((front == 0 && rear == MAX-1) || (front == rear+1))
	{
		printf("QUEUE OVERFLOW");
		return;
	}
	if(front == -1)
	{
		front = 0;
		rear = 0;
	}
	else
	{
		if(rear == MAX-1)
			rear = 0;
		else
			rear = rear+1;
	}
	cq[rear] = item ;
}

void deletion()
{
	if(front == -1)
	{
		printf("QUEUE UNDERFLOW");
		return ;
	}
	printf("Element deleted from queue is : %d ",cq[front]);
	if(front == rear)
	{
		front = -1;
		rear=-1;
	}
	else
	{
		if(front == MAX-1)
			front = 0;
		else
			front = front+1;
	}
}

void display()
{
	int front_pos = front,rear_pos = rear;
	if(front == -1)
	{
		printf("Queue is emptyn");
		return;
	}
	printf("Queue elements are : \n");
	if( front_pos <= rear_pos )
		while(front_pos <= rear_pos)
		{
			printf("%d ",cq[front_pos]);
			front_pos++;
		}
	else
	{
		while(front_pos <= MAX-1)
		{
			printf("%d ",cq[front_pos]);
			front_pos++;
		}
		front_pos = 0;
		while(front_pos <= rear_pos)
		{
			printf("%d ",cq[front_pos]);
			front_pos++;
		}
	}
}
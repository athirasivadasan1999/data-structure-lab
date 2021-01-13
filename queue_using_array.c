#include <stdio.h>
#define MAX 50
void insert();
void delete();
void display();
int q_array[MAX];
int rear= - 1;
int front= - 1;
int main()
{
    int ch;
    printf("\n **********QUEUE OPERATIONS**********");
    printf("\n\t1.INSERT\n");
    printf("\t2.DELETE\n");
    printf("\t3.DISPLAY\n");
    printf("\t4.QUIT ");
    printf("\n************************************\n\n");
    do
    {
        printf("Enter your choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf ("\n Invalid choice \n");
        } 
    }
    while(ch!=4);
    return 0;
} 
 
void insert()
{
    int add;
    if (rear == MAX -1)
    printf("QUEUE OVERFLOW\n");
    else
    {
        if (front == -1)
        front = 0;
        printf("Insert the element in queue : ");
        scanf("%d", &add);
        rear = rear + 1;
        q_array[rear] = add;
    }
}
 
void delete()
{
    if (front == - 1 || front > rear)
    {
        printf("QUEUE UNDERFLOW \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n", q_array[front]);
        front =front + 1;
    }
}
 
void display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
            {
            printf("%d ", q_array[i]);
            }
        printf("\n");
    }
}

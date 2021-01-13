#include<stdio.h>
int stack[100],ch,n,a,top,i;
void push();
void pop();
void display();
int main()
{
    top = -1;
    printf("\n Enter the size of stack : ");
    scanf("%d",&n);
    printf("\n **********STACK OPERATIONS**********");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
    printf("\n************************************\n\n");
    do
    {
        printf("\n Enter your Choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                push();
                break;
            }
            case 2:
            {
                pop();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                break;
            }
            default:
            {
                printf ("\n Invalid choice ");
            }
                
        }
    }
    while(ch!=4);
    return 0;
}

void push()
{
    if(top >= n-1)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        printf(" Enter a value to be pushed: ");
        scanf("%d",&a);
        top++;
        stack[top] =a;
    }
}

void pop()
{
    if(top <=-1)
    {
        printf("\nSTACK UNDERFLOW");
    }
    else
    {
        printf("\n The popped elements is %d",stack[top]);
        top--;
    }
}

void display()
{
    if(top >=0)
    {
        printf("\nstack elements are:  \n");
        for(i =top; i >=0; i--)
            {
            printf("\n%d ",stack[i]);
            }
    }
    else
    {
        printf("\nEMPTY STACK ");
    }
   
}

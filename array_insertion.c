#include<stdio.h>
int main()
{
    int array[100], pos, i, n, value;
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    printf("\nEnter %d elements\n", n);
    for(i = 0; i < n; i++)
	{
        scanf("%d", &array[i]);
	}

    printf("\nEnter the location where you want to insert new element:  ");
    scanf("%d", &pos);

    printf("\nEnter the value to insert: ");
    scanf("%d", &value);
    
    for(i = n-1; i >= pos-1; i--)
	{
        array[i+1] = array[i];
	}
    array[pos - 1] = value;
    printf("\nResultant array is: \n");
   
    for(i = 0; i <= n; i++) 
    {
        printf("%d  ", array[i]);
    }
    return 0;
}
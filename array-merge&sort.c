#include<stdio.h>
int main()
{
    int arr1[50], arr2[50], size1, size2, i,j, k, merge[100],a;
    printf("Enter the Size of 1st Array  : ");
    scanf("%d", &size1);
    printf("Enter  Elements of 1st Array : ");
    for(i=0; i<size1; i++)
    {
        scanf("%d", &arr1[i]);
        merge[i] = arr1[i];
    }
    k = i;
    printf("\nEnter the Size of 2nd Array  : ");
    scanf("%d", &size2);
    printf("Enter Elements of 2nd Array: ");
    for(i=0; i<size2; i++)
    {
        scanf("%d", &arr2[i]);
        merge[k] = arr2[i];
        k++;
    }
    printf("\nThe new array after merging is:\n");
    for(i=0; i<k; i++)
        printf("%d ", merge[i]);
    for(i = 0; i < k; ++i) 
        {
            for(j = i + 1; j < k; ++j)
            {
                if (merge[i] > merge[j]) 
                {
                    a =  merge[i];
                    merge[i] = merge[j];
                    merge[j] = a;
                }
            }
         }
        printf("\nThe numbers arranged in ascending order are given below \n");
        for (i = 0; i < k; ++i)
            printf("%d ", merge[i]);
}


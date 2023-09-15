#include<stdio.h>

void selection_sort(int*, int );
void display(int*, int);

int main(void)
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The array is: ");
    display(arr, n);
    printf("\n");
    selection_sort(arr, n);
    printf("The sorted array is ");
    display(arr, n);
    return 0;
}

void selection_sort(int *arr, int n)
{
    int i, j; 
    for(i=0; i<n-1; i++) //loop for passes
    {
        int min=i;
        for(j=i+1; j<n; j++)//loop for selecting the smallest number
        {
            if( arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int swap=arr[i];
            arr[i]=arr[min];
            arr[min]=swap;
            display(arr, n);
            printf("\n");
        }
    }
}

void display(int *arr, int n)
{
    for(int j=0; j<n; j++)
    {
        printf("%d ", arr[j]);
    }
}
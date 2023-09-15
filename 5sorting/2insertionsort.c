#include<stdio.h>

void insertion_sort(int*, int );
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
    insertion_sort(arr, n);
    printf("The sorted array is ");
    display(arr, n);
    return 0;
}

void insertion_sort(int *arr, int n)
{
    int i, j, temp; 
    for(i=1; i<n; i++) //loop to select items from the unsorted list & initially arr[0] is the sorted list
    {
        temp=arr[i];
        j=i-1; 
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
        display(arr, n);
        printf("\n");
    }
}

void display(int *arr, int n)
{
    for(int j=0; j<n; j++)
    {
        printf("%d ", arr[j]);
    }
}
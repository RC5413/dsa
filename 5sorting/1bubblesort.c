#include<stdio.h>

void bubble_sort(int*, int );
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
    bubble_sort(arr, n);
    printf("The sorted array is ");
    display(arr, n);
    return 0;
}

void bubble_sort(int *arr, int n)
{
    int i, j; //i for no. of passes & j for the no. of elements in the array
    for(i=0; i<n-1; i++)
    {
        int flag=0;
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
                flag = 1;
            }
        }
        display(arr, n);
        printf("\n");
        if( flag == 0)
        {
            break;
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
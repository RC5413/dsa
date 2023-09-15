#include<stdio.h>

void quick_sort(int*, int, int, int);
int partition(int *, int, int, int);
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
    int lb=0, ub=n-1;
    printf("The array is: ");
    display(arr, n);
    printf("\n");
    quick_sort(arr, lb, ub, n);
    printf("The sorted array is ");
    display(arr, n);
    return 0;
}

void quick_sort(int *arr, int lb, int ub, int n)
{
    if(lb<ub)
    {
        int loc = partition(arr, lb, ub, n);
        quick_sort(arr, lb, loc-1, n);
        quick_sort(arr, loc+1, ub, n);
    }
}

int partition(int *arr, int lb, int ub, int n)
{
    int pivot=arr[lb], temp;
    int start=lb, end=ub;
    while(start<end)
    {
        while(arr[start] <= pivot)
        {
            start++;
        }
        while(arr[end] > pivot)
        {
            end--;
        }
        if(start<end)
        {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
        }
    }
    temp = arr[lb];
    arr[lb] = arr[end];
    arr[end] = temp;
    display(arr, n);
    printf("\n");
    return end;
}

void display(int *arr, int n)
{
    for(int j=0; j<n; j++)
    {
        printf("%d ", arr[j]);
    }
}
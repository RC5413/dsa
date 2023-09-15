#include<stdio.h>

void merge_sort(int*, int, int, int);
void merge(int *, int, int, int, int);
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
    merge_sort(arr, lb, ub, n);
    printf("The sorted array is ");
    display(arr, n);
    return 0;
}

void merge_sort(int *arr, int lb, int ub, int n)
{
    if(lb<ub)
    {
        int mid = (lb+ub)/2;
        merge_sort(arr, lb, mid, n);
        merge_sort(arr, mid+1, ub, n);
        merge(arr, lb, mid, ub, n);
    }
}

void merge(int *arr, int lb, int mid, int ub, int n)
{
    int i=lb, j=mid+1, k=lb, b[n];
    while(i <= mid && j <= ub)
    {
        if(arr[i] <= arr[j])
        {
            b[k] = arr[i];
            i++;
        }
        else
        {
            b[k] = arr[j];
            j++;
        }
        k++;
    }
    if(i > mid)
    {
        while(j <= ub)
        {
            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while(i <= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
    for(k=lb; k<=ub; k++)
    {
        arr[k] = b[k];
    }
    display(arr, n);
    printf("\n");
}

void display(int *arr, int n)
{
    for(int j=0; j<n; j++)
    {
        printf("%d ", arr[j]);
    }
}
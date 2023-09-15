#include<stdio.h>

int low=0; 
void binary_search(int*, int, int);

int main(void)
{
    int n, check;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the numbers in ascending order: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the number to be checked: ");
    scanf("%d", &check);
    binary_search(arr, n, check);
    return 0;
}

void binary_search(int *arr, int n, int check)
{
    int target=0, mid, high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(check==arr[mid])
        {
            target=1;
            break;
        }
        else if(check<arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid +1;
        }
    }
    if(target == 1)
    {
        printf("%d is present in the list at position %d", check, mid+1);
    }
    else
    {
        printf("%d is not present in the list.", check);
    }
}
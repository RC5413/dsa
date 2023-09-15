#include<stdio.h>

void linear_search(int*, int, int);

int main()
{
    
    int check_num,n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of the array: ");
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number you want to check: ");
    scanf("%d", &check_num);
    linear_search(a, n, check_num);
    return 0;
}

void linear_search(int *a, int n, int check_num)
{
    int flag=1;
    for(int i=0; i<n; i++)
    {
        if(a[i]==check_num)
        {
            printf("%d is present in the list at %d position.\n", check_num, i+1);
            flag=0;
        }
    }
    if(flag!=0)
    {
        printf("%d is not present in the list", check_num);
    }
}
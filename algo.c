#include <stdio.h>
#include <stdlib.h>


int kthElement(int a[], int x, int b[], int y, int k)
{
    int i, j, n = x + y;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        if (i >= x)
        {
            arr[i] = b[i - x];
        }
        else
            arr[i] = a[i];
    }

    for (j = 0; j < n - 1; j++)
    {
        int min = j;
        for (i = j + 1; i < n; i++)
        {
            if (arr[i] < arr[min])
            {
                min = i;
            }
        }
        int temp = arr[min];
        arr[min] = arr[j];
        arr[j] = temp;
    }

    return arr[k - 1];
}



int main()
{
    int arr1[] = {2,5,8,1};
    int arr2[] = {3,6,7,0};
    int x = kthElement(arr1,4,arr2,4,6);
    printf("%d",x);
    return 0;
}



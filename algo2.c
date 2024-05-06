#include <stdio.h>
#include <stdlib.h>

int kthElement2(int a[], int x, int b[], int y, int k)
{
    int i =  0, j = 0,m =0, n = x + y;
    int arr[n];
    while (m < n)
    {
        if (a[i] < b[j])
        {
            arr[m] = a[i];
            printf("%d",arr[m]);
            i++;
        }
        else
        {
            arr[m] = b[j];
            printf("%d",arr[m]);
            j++;
        }
        m++;
    }
    return arr[k-1];
}

int main()
{
    int arr1[] = { 100, 112 ,256 ,349 ,770};
    int arr2[] = {72, 86 ,113 ,119 ,265 ,445 ,892};

    int xx = kthElement2(arr1,5,arr2,7,7);
    printf("\n%d\n\n",xx);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int kthElement2(int a[], int x, int b[], int y, int k) {
    if (x == 0) {
        return b[k - 1];
    }
    if (y == 0) {
        return a[k - 1];
    }

    if (a[0] < b[0]) {
        return (k == 1) ? a[0] : kthElement2(a + 1, x - 1, b, y, k - 1);
    } else {
        return (k == 1) ? b[0] : kthElement2(a, x, b + 1, y - 1, k - 1);
    }
}


int main() {
    int arr1[] = { 100, 112 ,256 ,349 ,770};
    int arr2[] = {72, 86 ,113 ,119 ,265 ,445 ,892};

    int xx = kthElement2(arr1, 5, arr2, 7, 7);
    printf("%d\n", xx);
    return 0;
}


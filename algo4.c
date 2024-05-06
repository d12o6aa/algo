#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int kthElement(int a[], int x, int b[], int y, int k) {
    int n = x + y;
    int arr[n];

    for (int i = 0; i < x; i++)
        arr[i] = a[i];
    for (int i = 0; i < y; i++)
        arr[x + i] = b[i];

    mergeSort(arr, 0, n - 1);

    return arr[k - 1];
}

int main() {
    int arr1[] = {2, 5, 8, 1};
    int arr2[] = {3, 6, 7, 0};
    int x = kthElement(arr1, 4, arr2, 4, 6);
    printf("%d\n", x);
    return 0;
}


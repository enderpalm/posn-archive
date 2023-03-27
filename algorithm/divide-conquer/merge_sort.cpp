#include <iostream>
#include <algorithm>
#include <time.h>

void merge(int arr[], int left, int right, int mid){
    int tempSize = right - left + 1;
    int temp[tempSize];
    int i = left, j = mid + 1;
    for (int k = 0; k < tempSize; k++){
        if (i > mid) temp[k] = arr[j++];
        else if (j > right) temp[k] = arr[i++];
        else temp[k] = arr[i] < arr[j] ? arr[i++] : arr[j++];
    }
    for (int i = left; i <= right; i++) arr[i] = temp[i - left];
}

void mergeSort(int arr[], int left, int right){
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, right, mid);
}

int main(){
    clock_t t;
    int size = 250000; int arr[size];
    for (int i = 0; i < size; i++) arr[i] = i;
    std::random_shuffle(&arr[0], &arr[size - 1]);

    // std::cout << "\nBefore sorted: ";
    // for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    t = clock();
    mergeSort(arr, 0, size - 1);
    t = clock() - t;
    double delta = ((double) t) / CLOCKS_PER_SEC;
    printf("Runtime: %.8f sec", delta);
    // std::cout << "\n\nAfter sorted: ";
    // for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    return 0;
}
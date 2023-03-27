#include <iostream>
#include <algorithm>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int left, int right){
    // int k = random() % (right - left + 1) + left;
    // std::swap(arr[k], arr[left]);
    int pivot = arr[left];
    int i = left, j = right + 1;
    while(i < j){
        // when j reach left, arr[left] = pivot 
        // asserting arr[j] > pivot to be false
        while(arr[--j] > pivot); 
        while(arr[++i] < pivot) if (i == right) break;
        if (i < j) swap(&arr[i], &arr[j]);
    }
    swap(&arr[left], &arr[j]);
    return j; // j = new pivot
}

void quickSort(int arr[], int left, int right){
    if (right <= left) return;
    int sep = partition(arr, left, right);
    quickSort(arr, left, sep - 1);
    quickSort(arr, sep + 1, right);
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    int size = 2000000; int arr[size];
    clock_t t;
    for (int i = 0; i < size; i++) arr[i] = i;
    std::random_shuffle(&arr[0], &arr[size - 1]);
    //std::cout << "\nBefore sorted: ";
    //for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    t = clock();
    quickSort(arr, 0, size - 1);
    t = clock() - t;
    double delta = ((double) t) / CLOCKS_PER_SEC;
    printf("\n%f\n", delta);
    // std::cout << "\n\nAfter sorted: ";
    // for (int i = 0; i < size; i++) std::cout << arr[i] << " ";
    return 0;
}
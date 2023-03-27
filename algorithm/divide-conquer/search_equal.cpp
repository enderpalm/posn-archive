#include <iostream>

int searchEqual(int arr[], int low, int high){
    if (low < high){
        int mid = (low + high) / 2;
        if (arr[mid] == mid) return mid;
        if (arr[mid] > mid) return searchEqual(arr, low, mid);
        if (arr[mid] < mid) return searchEqual(arr, mid + 1, high);
    }
    return -1;
}

int main(){
    int arr[] = {0,-4,-3,1,0,1,2,6,8,11,13,14,19,20,24,26,35,48,49,80,90,92};
    std::cout << searchEqual(arr, 0, sizeof(arr) / sizeof(arr[0]));
    return 0;
}

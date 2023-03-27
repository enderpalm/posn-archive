#include <bits/stdc++.h>

#define HEAP_SIZE 100

using namespace std;

int heap[HEAP_SIZE]; // min heap

void sieveUp(int *arr, int size){
    int par = size / 2;
    if (arr[size] > arr[par]){
        swap(arr[size], arr[par]);
        sieveUp(arr, par);
    }
}

void push(int *arr, int *size, int entry){
    arr[++*size] = entry;
    sieveUp(arr, *size);
}

int main(){
    int size = 10;
    int *s = new int(0);
    for (int i = 1; i <= size; i++){
        int n; cin >> n;
        push(heap, s, n);
    }
    for (int i = 0; i <= size + 1; i++) cout << heap[i] << " ";
    return 0;
} // 1 5 2 6 3 7 2 9 4 10
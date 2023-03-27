#include <iostream>
#include <math.h>

#define HEAP_SIZE 101

void siftUp(int heap[], int last){
    int par = last / 2;
    if (heap[par] < heap[last] || last == 0) return;
    std::swap(heap[last], heap[par]);
    siftUp(heap, last / 2);
}

void siftDown(int heap[], int size, int pos){
    int left = 2 * pos;
    int right = left + 1;
    int smaller = pos;
    if (left <= size && heap[left] < heap[pos]) smaller = left;
    if (right <= size && heap[right] < heap[pos]) smaller = right;
    if (smaller != pos) {
        std::swap(heap[smaller], heap[pos]);
        siftDown(heap, size, smaller);
    }

}

void insertHeap(int heap[], int *size, int key){
    heap[++(*size)] = key;
    siftUp(heap, *size);
}

int deleteHeap(int heap[], int *size){
    int pop = heap[1];
    heap[1] = heap[*size];
    siftDown(heap, --(*size), 1);
    return pop;
}

void buildHeap(int raw[]){
    int size = sizeof(raw) / 4;
    int start = size / 2 - 1;
    for (int i = start; i >= 0; i--) siftDown(raw, size, i);
}

void printHeap(int heap[], int size, bool skipZero){
    for (int i = skipZero; i <= size; i++) std::cout << heap[i] << " ";
}

int main(){
    std::cout << "--Min Heap Test Program--\nEnter heap entries (-1 as sentinel): ";
    int cuz[HEAP_SIZE], size=0, n;
    while(true){
        int in; std::cin >> in;
        if (in == -1) break;
        insertHeap(cuz, &size, in);
    }
    std::cout << "Heap as stored in an array: ";
    printHeap(cuz, size, true);
    std::cout << "\nEnter number of heap entries to delete: ";
    std::cin >> n;
    while(n--){
        std::cout << "Deleted: " << deleteHeap(cuz, &size) << "\n";
    }
    std::cout << "Remaining heap as stored in an array: ";
    printHeap(cuz, size, true);
    return 0;
}
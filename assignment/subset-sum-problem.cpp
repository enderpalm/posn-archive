#include <bits/stdc++.h>

bool picked[101];
int arr[] = {1,5,3,6,7,10};

void sumOfSubSet(int pick, const int target, int size, int partial=0){
    if (partial == target) {
        for (int i = 0; i < size; i++){
            if (picked[i]) std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return;
    }
    if (pick == size) return;
    picked[pick] = true;
    sumOfSubSet(pick + 1, target, size, partial + arr[pick]);
    picked[pick] = false;
    sumOfSubSet(pick + 1, target, size, partial);
}

int main(){
    int n = 6;
    bool picked[n];
    memset(picked, false, sizeof(picked));
    sumOfSubSet(0, 17, n);
    return 0;
}

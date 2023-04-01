#include <iostream>

#include <string.h>

#define mxSize 100

using namespace std;

char dp[mxSize][mxSize];

bool subsetSum(int arr[], int size, int k){
    if (dp[size][k] != -1) return dp[size][k];
    if (k == 0) return dp[size][k] = true;
    if (size == 0) return dp[size][k] = false;
    if (arr[size - 1] > k) return dp[size][k] = subsetSum(arr, size - 1, k);
    return dp[size][k] = subsetSum(arr, size - 1, k) || subsetSum(arr, size - 1, k - arr[size - 1]);
}

int main(){
    memset(dp, -1, sizeof(dp));
    int n, k;
    cout << "Size of array: "; cin >> n;
    int arr[n];
    cout << "Enter array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Target summation: "; cin >> k;
    printf("Array can%s be summed to %d\n", subsetSum(arr, n, k) ? "" : "not", k);
    return 0;
}
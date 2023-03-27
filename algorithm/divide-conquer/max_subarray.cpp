#include <iostream>
#include <limits.h>

struct pkg{
    int sum;
    int low;
    int high;

    pkg(int a, int b, int c){
        sum = a; low = b; high = c;
    }
};

/**
 * Divide crossing array into 2 sides around mid point
 * Finds LEFT and RIGHT max partial sum by looping out from MID,
 * then combines both partial sum, lpos, rpos and package them in pkg
 * \return pkg (sum, lpos, rpos)
*/
pkg findMaximumCrossingSubArray(int arr[], int low, int high, int mid){
    int partial=0, left = INT_MIN, right = INT_MIN;
    int lpos, rpos;
    for (int i = mid; i >= low; i--){
        partial += arr[i];
        if (partial > left){
            left = partial;
            lpos = i;
        }
    }
    partial = 0;
    for (int i = mid + 1; i <= high; i++){
        partial += arr[i];
        if (partial > right){
            right = partial;
            rpos = i;
        }
    }
    return pkg(left + right, lpos, rpos);
}

/**
 * Recursively divide raw array into left, right and crossing array,
 * then pick the max sum possible, package sum, lpos, rpos into pkg
 * \return pkg (sum, lpos, rpos)
*/
pkg findMaximumSubArray(int arr[], int low, int high){
    if (high == low) return pkg(arr[low], low, high);
    int mid = (low + high) / 2;

    pkg left = findMaximumSubArray(arr, low, mid);
    pkg right = findMaximumSubArray(arr, mid + 1, high);
    pkg crs = findMaximumCrossingSubArray(arr, low, high, mid);
    if (left.sum >= right.sum && left.sum >= crs.sum) return left;
    else if (right.sum >= left.sum && right.sum >= crs.sum) return right;
    else return crs;
}

int main(){
    int arr[] = {0,13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,-4,7};
    pkg best = findMaximumSubArray(arr, 1, sizeof(arr) / 4 - 1);
    printf("Max possible stonks is: %d\nBuy at day: %d\nSell at day: %d\n", best.sum, best.low, best.high);
    return 0;
}
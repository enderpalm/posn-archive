#include <string.h>

#include <iostream>

#define mxn 10

using namespace std;

int dp[mxn][mxn];

int knapSack(int bundle[][2], int obj, int weight) {
    if (dp[obj][weight] != -1) return dp[obj][weight];  // already computed
    if (obj == 0 || weight == 0)
        dp[obj][weight] = dp[obj][0] = dp[0][weight] = 0;  // zero capacity -- zero items
    else if (bundle[obj][1] > weight)
        return dp[obj][weight] = knapSack(bundle, obj - 1, weight);  // added weight'll exceed capacity
    else {
        int notPicked = knapSack(bundle, obj - 1, weight);                                 // skip this item, remaining weight & val doesn't change
        int picked = bundle[obj][0] + knapSack(bundle, obj - 1, weight - bundle[obj][1]);  // pick this item, add item's val, decrease remaining weight
        dp[obj][weight] = max(notPicked, picked);
    }
    return dp[obj][weight];
}

int main() {
    /**
     * @param [][0] Object's value
     * @param [][1] Object's weight
     */
    int bundle[][2] = {{1, 1}, {4, 3}, {5, 4}, {7, 5}};

    cout << "Val Wgt\n";
    for (int i = 0; i < sizeof(bundle) / 8; i++) {
        printf("%2d |%2d\n", bundle[i][0], bundle[i][1]);
    }
    memset(dp, -1, sizeof(dp));
    int ans = knapSack(bundle, 4, 7);
    printf("Maximum possible value: %d\n", ans);
    return 0;
}
#include <string.h>

#include <iostream>

#define mxn 10

using namespace std;

int dp[mxn][mxn];

int knapSack(int bundle[][2], int obj, int weight) {
    memset(dp[0], 0, sizeof(dp[0])); // fill horizontal [0] to 0
    for (int i = 0; i < mxn; i++) dp[i][0] = 0; // fill vertical [0] to 0
    for (int i = 1; i <= obj; i++){
        for (int j = 1; j <= weight; j++){
            if (bundle[i][1] > j) dp[i][j] = dp[i - 1][j]; // weight exceeded
            else {
                int pickedVal = bundle[i][0] + dp[i - 1][j - bundle[i][1]];
                dp[i][j] = max(dp[i - 1][j], pickedVal);
            }
        }
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
    int ans = knapSack(bundle, 4, 7);
    printf("Maximum possible value: %d\n", ans);
    return 0;
}
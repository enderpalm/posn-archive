#include <string.h>

#include <iostream>

#define mxn 1000

using namespace std;

int dp[mxn];

int coinChange(int values[], const int coins, int target) {
    if (dp[target] != -1) return dp[target];
    if (target == 0) return 0;
    dp[target] = INT_MAX;
    for (int i = 0; i < coins; i++) {
        if (values[i] <= target) {
            dp[target] = min(dp[target], coinChange(values, coins, target - values[i]) + 1);
        }
    }
    return dp[target];
}

int main() {
    memset(dp, -1, sizeof(dp));
    int coins, target;
    cout << "Number of coin types: ";
    cin >> coins;
    cout << "Target change: ";
    cin >> target;
    int values[coins];
    cout << "Coin values: ";
    for (int i = 0; i < coins; i++) cin >> values[i];
    cout << coinChange(values, coins, target);
    return 0;
}
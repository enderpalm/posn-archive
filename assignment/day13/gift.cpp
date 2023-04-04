#include <iostream>
#include <string.h>

using namespace std;

int gift[3000], best;
int dp[3001][1001];

int pickPair(int idx, int coup){
    // printf("i: %d, k: %d\n", idx, coup);
    if (dp[idx][coup] != -1) return dp[idx][coup];
    if (2 * coup - 1 > idx) return 2e8;
    if (coup == 1) {
        best = 2e8;
        for (int i = 0; i < idx; i++) {
            int cur = gift[i + 1] - gift[i];
            if (best > cur) best = cur;
        }
        return dp[idx][coup] = best;
    }
    int pick = pickPair(idx - 2, coup - 1) + (gift[idx] - gift[idx - 1]);
    int notPick = pickPair(idx - 1, coup);

    // printf("i: %d, k: %d, Pick: %d  NotPick: %d\n", idx, coup, pick, notPick);
    return dp[idx][coup] = min(pick, notPick);
}

int main(){
    int k, n;
    cin >> k >> n;
    for (int i = 0; i < n; i++) cin >> gift[i];
    memset(dp, -1, 12016004);
    cout << pickPair(n - 1, k) << "\n";
    return 0;
}
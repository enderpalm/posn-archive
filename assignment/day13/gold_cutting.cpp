#include <bits/stdc++.h>

using namespace std;

int dp[11], gold[11];

int chop(int len){
    if (dp[len] != -1) return dp[len];
    if (len == 1) return gold[len];
    for (int i = 1; i < len; i++)
        dp[len] = max(dp[len], gold[i] + chop(len - i));
    return dp[len] = max(dp[len], gold[len]);
}

int main(){
    int n; cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= n; i++) cin >> gold[i];
    cout << chop(n) << "\n";
    return 0;
}
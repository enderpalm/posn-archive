#include <bits/stdc++.h>

using namespace std;

using chrono::duration_cast;
using chrono::milliseconds;
using chrono::system_clock;

#define size 5001

int dp[size][size]; // using dp

// int check(int n, int p, int start){
//     int cnt = 0;
//     if (n == 0) return ++cnt;
//     for (int i = start; pow(i, p) <= n; i++){
//         int trial = pow(i, p);
//         cnt += check(n - trial, p , i + 1);
//     }
//     return cnt;
// }

int checkv2(int n, int p, int start){
    if (dp[n][start] != 0) return dp[n][start]; // already has ans
    if (n == 0) {
        return dp[n][start] = 1;
    }
    for (int i = start; pow(i, p) <= n; i++){
        int trial = pow(i, p);
        dp[n - trial][i + 1] = checkv2(n - trial, p , i + 1);
        dp[n][start] += dp[n - trial][i + 1];
    }
    return dp[n][start];
}



int main(){
    cin.tie(0)->sync_with_stdio(false);
    int x, n;
    cin >> x >> n;
    memset(dp, 0, sizeof(dp));
    auto millisec_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    //cout << check(x, n, 1);
    checkv2(x, n ,1);
    cout << dp[x][1] << "\n";
    cout << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - millisec_since_epoch << "\n";
    return 0;
}  
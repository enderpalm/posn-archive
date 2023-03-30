#include <iostream>

using namespace std;

typedef long long ll;

bool hasDog[51][51];
ll dp[51][51];

int main(){
    cin.tie(nullptr);
    int dogCnt, a, b, horz, vert;
    cin >> horz >> vert >> dogCnt;
    for (int i = 0; i < dogCnt; i++) {
        cin >> a >> b;
        hasDog[a][b] = true;
    }
    dp[1][1] = 1;
    for (int i = 1; i <= horz; i++){
        for (int j = 1; j <= vert; j++){
            if (i == 1 && j == 1) continue;
            if (hasDog[i][j]) dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[horz][vert] << endl;
    return 0;
}

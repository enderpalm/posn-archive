#include <iostream>

using namespace std;

int main(){
    int rnd = 20;
    long long m, n, ans;
    for (int i = 0; i < rnd; i++){
        cin >> m >> n;
        ans = (n << 1) - (m >> 1);
        ans = (ans <= n && ans >= 0) ? ans + 1 : 0;
        cout << ans << endl;
    }
    return 0;
}
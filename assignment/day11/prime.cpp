#include <bits/stdc++.h>

using namespace std;

#define int long long int

const int mxn = 8e6;

bitset<mxn> compound;

int32_t main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, cnt=0; cin >> n;
    for (int i = 2; i <= mxn; i++) {
        if (!compound[i]){
            cnt++;
            if (cnt == n) {
                cout << i << "\n";
                return 0;
            }
            for (int j = i * i; j <= mxn; j += i) compound[j] = true;
        }
    }
    return 0;
}

#include <iostream>

using namespace std;

typedef long long int ll;

const int lim = 1e6 + 1;
int M; ll N;
int perm[lim];

bool doable(ll time){
    ll movable = 0;
    for (int i = 0; i < M; i++) movable += time / perm[i];
    return movable >= N;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int mx = INT32_MIN;
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> perm[i];
        if (mx < perm[i]) mx = perm[i];
    }
    ll lo=1, hi = N * mx, ans=0;
    while(lo <= hi){
        ll mid = (lo + hi) / 2;
        if (doable(mid)) {
            hi = mid - 1;
            ans = mid;
        } else lo = mid + 1;
    }
    cout << ans << endl;
    return 0;
}
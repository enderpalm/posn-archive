#include <iostream>

using namespace std;

int cwire, croom, require[101];

bool enough(int bandwidth){
    int cnt = 1, sum = 0;
    for (int i = 0; i < croom; i++){
        sum += require[i];
        if (sum > bandwidth) {
            sum = require[i];
            cnt++;
        }
    }
    return cwire >= cnt;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> cwire >> croom;
    int lo = INT32_MIN, hi = 0, ans;
    for (int i = 0; i < croom; i++) {
        cin >> require[i];
        hi += require[i];
        if (require[i] > lo) lo = require[i];
    }
    while(lo <= hi){
        int mid = (lo + hi) >> 1;
        if (enough(mid)) {
            ans = mid;
            hi = mid - 1;
        } else lo = mid + 1;
    }
    cout << ans << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, entry, left=0;
    unordered_map<int, int> freq;
    cin >> n >> m;
    while(n--){
        cin >> entry;
        freq[entry] = (++freq[entry]) % m;
    }
    for (auto m : freq) left += m.second;
    cout << left << endl;
    return 0;
}
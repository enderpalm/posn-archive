/*
TASK: medal.cpp
LANG: C++
AUTHOR: Chawanwit Chitman
CENTER: Thammasat Rangsit
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int mx = 500000;

int n, person[mx], podium[mx], ht[mx];

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> person[i];
    for (int i = 0; i < n; i++) cin >> podium[i];
    sort(person, person + n);
    sort(podium, podium + n, greater<int>());
    for (int i = 0; i < n; i++) ht[i] = person[i] + podium[i];
    sort(ht, ht + n);
    cout << ht[n - 1] - ht[0] << "\n";
    return 0;
}
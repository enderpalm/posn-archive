#include <iostream>
#include <math.h>

using namespace std;

int powerSum(int x, int n){
    if (x == 1) return 1;
    return pow(x, n) + powerSum(x - 1, n);
}

int main(){
    int x, n;
    cin.tie(0)->sync_with_stdio(false);
    cin >> x >> n;
    cout << powerSum(x, n) << "\n";
    return 0;
}
#include <iostream>

#define mxn 93
#define int long long int

using namespace std;

int top[mxn];

int fiboTop(int n) {
   if (n < 2) return n;
   if (top[n]) return top[n];
   return top[n] = fiboTop(n - 1) + fiboTop(n - 2);
}

int bottom[mxn];

int fiboBottom(int n){
    bottom[0] = 0; bottom[1] = 1;
    for (int i = 2; i <= n; i++) {
        bottom[i] = bottom[i - 1] + bottom[i - 2];
    }
    return bottom[n];
}

int32_t main(){
    int16_t n;
    cin >> n;
    printf("Element %d in fibo (Memoization) : %lld\n", n, fiboTop(n));
    printf("Element %d in fibo (Bottom-Up)    : %lld\n", n, fiboBottom(n));
    return 0;
}
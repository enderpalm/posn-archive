#include <iostream>
#include <string.h>

using namespace std;

bool brute_prime(int n){
    if (n < 2) return false;
    for (int i = 2; i * i < n; i++){
        if (!(n % i)) return false;
    }
    return true;
}

bool sieveOfEratosthenes(int n){
    bool prime[n + 1];
    memset(prime, true, n + 1);
    for (int i = 2; i * i <= n; i++){
        if (prime[i]) {
            for (int j = 2 * i; j <= n; j += i) prime[j] = false;
        }
    }
    return prime[n];
}

int main(){
    int n; cin >> n;
    printf("%d is %sa prime\n", n, sieveOfEratosthenes(n) ? "" : "not ");
    return 0;
}

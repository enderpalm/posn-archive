#include <iostream>

using namespace std;

int n, k;

const int maxDegree = 10;

int top[maxDegree][maxDegree + 1];

int coefTop(int n, int k){
    if (k > n) return 0;
    if (k == 0 || n == k) return 1;
    if (top[n][k]) return top[n][k];
    return top[n][k] = coefTop(n - 1, k - 1) + coefTop(n - 1, k);
}

int bottom[maxDegree][maxDegree + 1];

int coefBottom(int n, int k){
    bottom[0][0] = 1;
    for (int i = 1; i <= n + 1; i++){
        for (int j = 1; j <= i; j++){
            bottom[i][j] = bottom[i - 1][j] + bottom[i - 1][j - 1];
        }
    }
    return bottom[n + 1][k + 1];
}

int main(){
    cin >> n >> k;
    printf("[Top-Down] Binomial Coef.  (n: %d, k: %d) = %d\n", n, k, coefTop(n, k));
    printf("[Bottom-Up] Binomial Coef. (n: %d, k: %d) = %d\n", n, k, coefBottom(n, k));
    return 0;
}

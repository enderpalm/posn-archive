#include <iostream>

using namespace std;

int fibo(int n){
    if (n < 2) return n;
    return fibo(n - 1) + fibo(n - 2);
}

int main(){
    for (int i = 1; i < 10; i++) cout << fibo(i) << "\n";
    return 0;
}

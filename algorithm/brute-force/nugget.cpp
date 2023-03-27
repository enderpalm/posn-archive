#include <iostream>
#include <string.h>
#include <chrono>

bool mem[1000001];

using std::chrono::duration_cast;
using std::chrono::milliseconds;
using std::chrono::system_clock;

int nuggets[] = {6, 9, 20};

bool isNugget(int n){
    if (n < 6) return false;
    if (mem[n]) return mem[n];
    if (n == 6 || n == 9 || n == 20) return mem[n] = true;
    for (int i = 0; i < 3; i++){
        if (isNugget(n - nuggets[i])) return mem[n] = true;
    }
    return mem[n] = false;
}

int main(){
    std::cin.tie(nullptr)->sync_with_stdio(false);
    memset(mem, false, sizeof(mem));
    int bound; std::cin >> bound;
    if (bound < 6) {
        std::cout << "no" << "\n";
        return 0;
    }
    
    auto millisec_since_epoch = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    for (int i = 6; i <= bound; i++) {
        //if (isNugget(i)) std::cout << i << "\n";
        isNugget(i);
    }
    std::cout << "milliseconds since epoch: " << duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - millisec_since_epoch << std::endl;
    return 0;
}
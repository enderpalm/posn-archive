#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    string literal;
    int rnd = 20, len;
    while(rnd--){
        cin >> len >> literal;
        int zeroCnt = count(literal.begin(), literal.end(), '0');
        int secCnt = count(literal.begin() + 2, literal.end(), '0');
        if (literal[0] != '0' || zeroCnt == 0 || (literal[1] != '2' && secCnt == 0)) 
            cout << "no" << "\n";
        else cout << "yes" << "\n";
    }
    return 0;
}
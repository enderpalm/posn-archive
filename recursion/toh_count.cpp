#include <iostream>

using namespace std;

int countMoves(int n, char start, char end, char aux){
    int count = 0;
    if (n == 1) {
        count++;
        return count;
    }
    count += countMoves(n - 1, start, aux, end); // move top n - 1 to aux
    count += countMoves(1, start, end, aux);
    count += countMoves(n - 1, aux, end, start); // move top n - 1 from aux to end                                       // after base case (moved bottom)
    return count;
}

int main(){
    int n;
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    cout << countMoves(n, 'A', 'B', 'C') << "\n";
    return 0;
}
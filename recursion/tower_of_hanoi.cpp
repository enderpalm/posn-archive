#include <iostream>

using namespace std;

void countMoves(int n, char start, char end, char aux){
    if (n == 1){
        printf("Move disk 1 (%c -> %c)\n", start, end); // move bottom to dest
        return;
    }
    countMoves(n - 1, start, aux, end); // move top n - 1 to aux
    printf("Move disk %d (%c -> %c)\n",n,start, end);
    countMoves(n - 1, aux, end, start); // move top n - 1 from aux to end 
                                          // after base case (moved bottom)
}

int main(){
    int n = 6;
    countMoves(n, 'A', 'B', 'C');
    return 0;
}
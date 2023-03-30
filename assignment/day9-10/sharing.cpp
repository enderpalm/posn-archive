#include <bits/stdc++.h>

using namespace std;

int s[10];
int target, quan;

void distribute(int& done, int& ways, int picking, int partial = 0) {
    if (picking > quan) return;
    if (partial >= target) {
        if (done > partial) {
            done = partial;
            ways = 1;
        } else if (done == partial)
            ways++;
        return;
    }
    distribute(done, ways, picking + 1, partial + s[picking]);
    distribute(done, ways, picking + 1, partial);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> target >> quan;
    for (int i = 0; i < quan; i++) cin >> s[i];
    int count = INT_MAX, ways = 0;
    distribute(count, ways, 0);
    printf("%d\n%d", ways, count == INT_MAX ? 0 : count);
    return 0;
}

/*
5 4
2 5 10 2
*/
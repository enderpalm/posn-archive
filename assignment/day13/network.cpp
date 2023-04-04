#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct Compare{
    bool operator()(pii a, pii b){
        return a.first > b.first;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, start, end, use, steak = 0;
    bool duringSteak = false;
    cin >> n >> m;
    priority_queue<pii, vector<pii> ,Compare> events;
    for (int i = 0; i < n; i++) {
        cin >> start >> end >> use;
        events.push({start, use});
        events.push({end + 1, -use});
    }
    // cout << "\n";
    while(!events.empty()) {
        auto v = events.top(); events.pop();
        auto next = events.top();
        steak += v.second;
        // printf("%d %d %d\n", v.first, v.second, steak);
        if (!events.empty() && v.first == next.first) continue;
        if (steak >= m && !duringSteak) {
            duringSteak = true;
            // printf("started at: %d\n", v.first);
            start = v.first;
        } else if (steak < m && duringSteak) {
            //if (steak + next.second >= m && next.first - v.first == 1) continue;
            duringSteak = false;
            // printf("ended at: %d\n", v.first);
            cout << start << " " << v.first - 1 << "\n";
        }
    }
    return 0;
}

/*
2 10
1 10 50
11 20 55

4 30
10 50 10
20 40 10
40 50 20
30 45 10
30 50

/*
5 30
1 10 20
1 10 9
11 20 9
11 20 2
11 20 1

3 20
1 2 20
2 3 20
3 4 20
*/

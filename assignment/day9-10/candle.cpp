#include <queue>
#include <utility>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

const int mx = 2001;
int m, n;

char mapping[mx][mx];

pii dir[8] = {{1, 1}, {1, 0}, {1, -1}, {0, 1}, {0, -1}, {-1, 1}, {-1, 0}, {-1, -1}};

bool isValid(int x, int y) {
    return x >= 0 && y >= 0 && x < m && y < n && mapping[x][y] == '1';
}

void transverse(int ox, int oy) {
    queue<pii> q;
    mapping[ox][oy] = '2';
    q.emplace(ox, oy);
    while (!q.empty()) {
        auto next = q.front();
        q.pop();
        for (auto d : dir) {
            int nx = next.first + d.first, ny = next.second + d.second;
            if (isValid(nx, ny)) {
                mapping[nx][ny] = '2';
                q.emplace(nx, ny);
            }
        }
    }
}

int countIsolate() {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mapping[i][j] == '1') {
                transverse(i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) cin >> mapping[i][j];
    cout << countIsolate() << endl;
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

// first = tar, second = weight
typedef pair<int, int> pii;
typedef vector<pii> vint;

void append(vint g[], int u, int v, int w){
    g[u].push_back(make_pair(v, w));
    g[v].push_back(make_pair(u, w));
}

void printGraph(vint g[], int size){
    for (int i = 0; i < size; i++){
        printf("%d: ", i);
        for (auto j : g[i]) printf("(%d, %d) ", j.first, j.second);
        cout << "\n";
    }
}

int travel(vint graph[], int size, int start){
    int nei[size - 1], ans = INT32_MAX;
    for (int i = 1; i < size; i++) nei[i - 1] = graph[start][i - 1].first;
    do {
        int sum = 0;
        sum += graph[start][nei[0]].second;
        for (int i = 0; i < size - 2; i++) sum += graph[nei[i]][nei[i + 1]].second;
        sum += graph[nei[size - 2]][0].second;
        ans = min(ans, sum);
    } while (next_permutation(nei, nei + size - 1));
    return ans;
}

int main(){
    int size = 4;
    vint adj[size];
    append(adj, 0, 1, 2);
    append(adj, 0, 2, 5);
    append(adj, 0, 3, 7);
    append(adj, 1, 2, 8);
    append(adj, 1, 3, 3);
    append(adj, 2, 3, 1);
    //printGraph(adj, size);
    printf("Minimum travelling is: %d\n", travel(adj, size, 0));
    return 0;
}
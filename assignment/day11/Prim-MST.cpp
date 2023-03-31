#include <algorithm>
#include <array>
#include <iostream>
#include <climits>
#include <queue>
#include <utility>
#include <vector>

#define size 8

typedef std::array<int, size> arr;
typedef std::pair<int, int> pii;
typedef std::vector<pii> adj;
typedef std::pair<arr, arr> bundle;

void append(adj g[], char src, char dest, int weight) {
    int s = src - 65, d = dest - 65;
    g[s].push_back({weight, d});
    g[d].push_back({weight, s});
}

void printAdjacent(adj g[]) {
    for (int i = 0; i < size; i++, std::cout << "\n") {
        printf("%c: ", i + 65);
        for (auto v : g[i]) printf("(%c, %d) ", v.first + 65, v.second);
    }
}

bundle primmy(adj graph[], char src) {
    src -= 65;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    arr dist, visited, parent;
    std::fill(dist.begin(), dist.end(), INT_MAX);
    std::fill(visited.begin(), visited.end(), false);
    dist[src] = 0;
    visited[src] = true;
    pq.push({0, src});
    while (!pq.empty()) {
        auto srcVert = pq.top().second;
        pq.pop();
        for (auto neighbor : graph[srcVert]) {
            int weight = neighbor.first;
            int label = neighbor.second;
            if (dist[label] >  weight && !visited[label]) {
                dist[label] = weight;
                parent[label] = srcVert;
                pq.push({dist[label], label});
            }
        }
    }
    return std::make_pair(dist, parent);
}

void printGraph(bundle data){
    printf("Edge  Wgh\n");
    for (int i = 1; i < size; i++)
        printf("%c--%c | %d\n", data.second[i] + 65, i + 65, data.first[i]);
}

int main() {
    adj graph[size];
    append(graph, 'A', 'B', 8);
    append(graph, 'A', 'C', 2);
    append(graph, 'A', 'D', 5);
    append(graph, 'B', 'D', 2);
    append(graph, 'B', 'F', 13);
    append(graph, 'C', 'D', 2);
    append(graph, 'C', 'E', 5);
    append(graph, 'D', 'E', 1);
    append(graph, 'D', 'F', 6);
    append(graph, 'D', 'G', 3);
    append(graph, 'E', 'G', 1);
    append(graph, 'F', 'G', 2);
    append(graph, 'F', 'H', 3);
    append(graph, 'G', 'H', 6);
    // printAdjacent(graph);
    char start = 'A';
    printGraph(primmy(graph, start));
    return 0;
}
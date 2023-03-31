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

bundle dijkstra(adj graph[], char src) {
    src -= 65;
    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    arr dist, parent;
    std::fill(dist.begin(), dist.end(), INT_MAX);
    dist[src] = 0;
    parent[src] = -1;
    pq.push({0, src});
    while (!pq.empty()) {
        auto srcVert = pq.top().second;
        pq.pop();
        for (auto neighbor : graph[srcVert]) {
            int weight = neighbor.first;
            int label = neighbor.second;
            if (dist[label] > dist[srcVert] + weight) {
                dist[label] = dist[srcVert] + weight;
                pq.push({dist[label], label});
                parent[label] = srcVert;
            }
        }
    }
    return std::make_pair(dist, parent);
}

void printPath(arr parent, int src) {
    if (parent[src] == -1) return;
    printPath(parent, parent[src]);
    printf(" → %c", src + 65);
}

void printShortest(bundle dist, char src) {
    for (int i = 0; i < size; i++) {
        printf("%c → %c: %d\t", src, i + 65, dist.first.at(i));
        printf("%c", src);
        printPath(dist.second, i);
        std::cout << "\n";
    }
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
    printf("Dist from %c\tPath:\n", start);
    printShortest(dijkstra(graph, start), start);
    return 0;
}
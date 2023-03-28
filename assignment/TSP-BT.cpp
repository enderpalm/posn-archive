#include <iostream>
#include <string.h>

#define GRAPH_SIZE 4

using namespace std;

int graph[GRAPH_SIZE][GRAPH_SIZE];
int visited[GRAPH_SIZE];

void append(int u, int v, int w){
    graph[u][v] = graph[v][u] = w;
}

void printMatrix(){
    cout << "Adjacency Matrix:\n";
    for (int i = 0; i < GRAPH_SIZE; i++, cout << "\n")
        for (int j = 0; j < GRAPH_SIZE; j++)
            cout << graph[i][j] << " ";
}

void travel(int& ans, int cur, int partial=0, int cnt=1){
    int curCost = graph[cur][0];
    if (cnt == GRAPH_SIZE && curCost){
        ans = min(ans, curCost + partial);
        return;
    }
    for (int i = 0; i < GRAPH_SIZE; i++){
        if (!visited[i] && graph[cur][i]){
            visited[i] = cnt + 1;
            travel(ans, i ,partial + graph[cur][i], cnt + 1);
            visited[i] = 0;
        }
    }
}

int main(){
    int start = 0;
    memset(graph, 0, sizeof(&graph));
    memset(visited, 0, GRAPH_SIZE);
    append(0, 1, 2);
    append(0, 2, 5);
    append(0, 3, 7);
    append(1, 2, 8);
    append(1, 3, 3);
    append(2, 3, 1);
    //printMatrix();
    int ans = INT32_MAX;
    visited[start] = 1;
    travel(ans, start);
    printf("Minimum travel possible: %d\n", ans);
    return 0;
}
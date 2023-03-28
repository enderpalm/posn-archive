#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Graph{
    map<char, vector<char>> neighbor;
    map<char, bool> visited;

    public:
        void append(char start, char dest);
        void printGraph();
        void dfs(char start);
};

void Graph::append(char start, char dest){
    this->neighbor[start].push_back(dest);
}

void Graph::printGraph(){
    cout << "---Adjacency List---\n";
    for (auto m : neighbor){
        cout << m.first << ": ";
        for (auto n : m.second) cout << n << " ";
        cout << "\n";
    }
    cout << "---------------------\n";
}

void Graph::dfs(char start){
    visited[start] = true;
    printf("%c ", start);
    for (auto n : this->neighbor[start]){
        if (!visited[n]) dfs(n);
    }
}

int main(){
    Graph graph;
    graph.append('A', 'C');
    graph.append('A', 'G');
    graph.append('B', 'A');
    graph.append('C', 'B');
    graph.append('C', 'H');
    graph.append('D', 'E');
    graph.append('D', 'F');
    graph.append('E', 'F');
    graph.append('G', 'D');
    graph.append('G', 'E');
    graph.append('H', 'A');
    graph.append('H', 'D');
    graph.append('S', 'A');
    graph.append('S', 'B');
    graph.append('S', 'C');
    graph.printGraph();
    
    cout << "Vertices visited in DFS: ";
    graph.dfs('S');
    cout << "\n";
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

struct Node{
    int freq;
    char c;
    struct Node *left, *right;

    Node(char ch, int freq, struct Node *left=nullptr, struct Node *right=nullptr){
        this->freq = freq;
        this->c = ch;
        this->left = left;
        this->right = right;
    }
};

typedef struct Node *node;

struct compare{
    bool operator()(node below, node above){
        return (below->freq > above->freq);
    }
};

void printCode(node root, string prev){
    if (root == nullptr) return;
    if (root->c != '#') printf("%c : %s\n", root->c, prev.c_str());
    printCode(root->left, prev + "0");
    printCode(root->right, prev + "1");
}

node buildHuffman(char ch[], int freq[], int size){
    priority_queue<node, vector<node>, compare> heap;
    for (int i = 0; i < size; i++) heap.push(new Node(ch[i], freq[i]));
    while(heap.size() > 1){
        node left = heap.top(); heap.pop();
        node right = heap.top(); heap.pop();
        node combine = new Node('#', left->freq + right->freq, left, right);
        heap.push(combine);
    }
    printCode(heap.top(), "");
    return heap.top();
}

int main(){
    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
    int freq[] = {45, 13, 12, 16, 9, 5, 100, 35};
    int size = sizeof(freq) / 4;
    buildHuffman(ch, freq, size);
    return 0;
}
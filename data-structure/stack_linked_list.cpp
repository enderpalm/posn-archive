#include <iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
};

typedef struct Node *node;

struct Stack{
    int top = -1;
    node list = NULL;
};

typedef struct Stack stack;

bool isEmpty(stack *s){
    return s->top == -1;
}



int main(){

}
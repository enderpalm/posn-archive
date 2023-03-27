#include <iostream>

#define STKSZ 100

using namespace std;

struct Stack{
    int top = -1;
    int store[STKSZ];
};

typedef struct Stack stack;

stack s;

void stackUnderflow(){
    cout << "Stack Underflow!!" << "\n";
    exit(1);
}

void empty(stack *s){
    s->top = -1;
}

bool isEmpty(stack *s){
    return s->top == -1;
}

int top(stack *s){
    if (isEmpty(s)) stackUnderflow();
    return s->store[s->top];
}

void push(stack *s, int entry){
    if (s->top >= STKSZ) {
        cout << "Stack Overflow!!" << "\n";
        exit(1);
    }
    s->store[++s->top] = entry;
}

int pop(stack *s){
    if (isEmpty(s)) stackUnderflow();
    return s->store[s->top--];
}

void printStack(stack *s){
    if (isEmpty(s)) stackUnderflow();
    else {
        cout << "[" << s->top;
        int i = s->top + 1;
        while(i--){
            cout << " " << s->store[i];
        }
        cout << "]\n";
    }
}


int main(){
    stack stk;
    push(&stk, 7);
    push(&stk, 9);
    push(&stk, 2);
    pop(&stk);
    push(&stk, 3);
    printStack(&stk);
    if (stk.top != 1){
        return 0;
    }
    return 0;
}


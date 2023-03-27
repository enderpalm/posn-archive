#include <iostream>

using namespace std;

#define STACK_SIZE 100

struct Stack{
    int top = -1;
    char store[STACK_SIZE];
};

typedef struct Stack stack;

stack s;

bool isEmpty(stack *s){
    return s->top == -1;
}

void push(stack *s, char entry){
    if (s->top >= STACK_SIZE) exit(1);
    s->store[++s->top] = entry;
}

char pop(stack *s){
    if (isEmpty(s)) exit(1);
    return s->store[s->top--];
}

char getCls(char opn){
    if (opn == '[') return ']';
    if (opn == '{') return '}';
    if (opn == '(') return ')';
    else exit(1);
}

int main(){
    string raw; cin >> raw;
    stack brac;
    bool valid = true;
    for (char c : raw){
        if (c == '[' || c == '(' || c == '{') push(&brac, c);
        if (c == ']' || c == ')' || c == '}') {
            if (isEmpty(&brac)) { 
                valid = false;
                break;
            } else {
                char opn = pop(&brac);
                if (getCls(opn) != c) {
                    valid = false;
                    break;
                }
            }
        }
    }
    if (!isEmpty(&brac)) valid = false;
    
    printf("%s\n", valid ? "Valid" : "Invalid");
    return 0;
}
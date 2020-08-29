//
//  main.cpp
//  Reverse a stack
//
//  Created by Giriraj Saigal on 29/08/20.
//  Copyright © 2020 Giriraj Saigal. All rights reserved.
//

#include <iostream>
#include "vector"
using namespace std;

int calls = 0;

struct Stack{
    int* arr;
    int top;
    int size;
};
Stack* createStack(int size){
    Stack *s = new Stack;
    s->arr = new int[size];
    s->top = -1;
    s->size = size;
    return s;
}
void push(Stack* s, int d){
    
    if(s->top == s->size-1){
        return;
    }
    
    s->top++;
    s->arr[s->top] = d;
}
int pop(Stack* s){
    
    if(s->top == -1){
        return INT_MIN;
    }
    return s->arr[s->top--];
}
int isEmpty(Stack* s){
    return s->top==-1;
}
int peak(Stack *s){
    return s->arr[s->top];
}

void insertBottom(Stack* s, int x){
    
    if(isEmpty(s)){
        push(s, x);
        return;
    }
    
    int val = pop(s);
    insertBottom(s, x);
    push(s, val);
}

void reverseStack(Stack* s){
    
    if(isEmpty(s)){
        return;
    }
    
    int x = pop(s);
    reverseStack(s);
    insertBottom(s,x);
}

int main(int argc, const char * argv[]) {
    Stack *s = createStack(10);
    push(s, 160);
    push(s, 21);
    push(s, 102);
    push(s, 153);
    push(s, 260);
    push(s, 53);
    
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    
    push(s, 160);
    push(s, 21);
    push(s, 102);
    push(s, 153);
    push(s, 260);
    push(s, 53);
    
    reverseStack(s);

    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;
    cout<<pop(s)<<endl;

    return 0;
}


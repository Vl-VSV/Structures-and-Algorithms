//
//  functions 2.cpp
//  Number 3
//
//  Created by Vlad V on 05.03.2023.
//

#include "functions 2.hpp"
#include <iostream>
#include <cmath>

using namespace std;

bool Stack:: isEmpty(){
    return top == -1;
}

bool Stack::isFull(){
    return top == MAX_SIZE - 1 ;
}

void Stack::push(int item){
    if(isFull()){
        cout << "Error: Stack overflow" << endl;
        exit(1);
    }
    stack[++top] = item;
}

void Stack::pop(){
    if(isEmpty()){
        cout << "Error: Stack underflow" << endl;
        exit(1);
    }
    top--;
}

int Stack::peek(){
    if(isEmpty()){
        cout << "Error: Stack is empty" << endl;
        exit(1);
    }
    return stack[top];
}

int evaluatePrefix(string prefix){
    Stack opStack;
    
    for (int i = (int)prefix.length() - 1; i >= 0; i--){
        char c = prefix[i];
        
        if(isdigit(c)){
            opStack.push(c - '0');
        } else {
            int operand1 = opStack.peek();
            opStack.pop();
            int operand2 = opStack.peek();
            opStack.pop();
            
            switch (c) {
                case '+':
                    opStack.push(operand1 + operand2);
                    break;
                case '-':
                    opStack.push(operand1 - operand2);
                    break;
                case '*':
                    opStack.push(operand1 * operand2);
                    break;
                case '/':
                    opStack.push(operand1 / operand2);
                    break;
                case '^':
                    opStack.push(pow(operand1, operand2));
                    break;
                default:
                    break;
            }
        }
    }
    
    return opStack.peek();
}

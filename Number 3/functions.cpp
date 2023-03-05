//
//  functions.cpp
//  Number 3
//
//  Created by Vlad V on 05.03.2023.
//

#include "functions.hpp"
#include <stack>
#include <cmath>

using namespace std;

bool isOperator(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int getPrecedence(char op){
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    else
        return 0;
}

string infixToPostfix(string infix) {
    stack<char> opStack;
    string postfix = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if (isOperator(c)) {
            while (!opStack.empty() && opStack.top() != '(' && getPrecedence(opStack.top()) >= getPrecedence(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        } else if (c == '(') {
            opStack.push(c);
        } else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop();
        } else { // Operand
            postfix += c;
        }
    }
    
    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }
    
    return postfix;
}

string postfixToInfix(string prefix) {
    stack<string> opStack;
    
    for (int i = 0; i < prefix.length(); i++) {
        if (isOperator((prefix[i]))) {
            
            string op1 = opStack.top();
            opStack.pop();
            
            string op2 = opStack.top();
            opStack.pop();
            
            opStack.push("(" + op2 + prefix[i] + op1 + ")");
        } else {
            opStack.push(string(1, prefix[i]));
        }
    }
    return opStack.top();
}

string infixToPrefix(string infix)
{
    reverse(infix.begin(), infix.end());
    
    for (int i = 0; i < infix.length(); i++) {
 
        if (infix[i] == '(') {
            infix[i] = ')';
        }
        else if (infix[i] == ')') {
            infix[i] = '(';
        }
    }
 
    string prefix = infixToPostfix(infix);
    reverse(prefix.begin(), prefix.end());
 
    return prefix;
}

int evaluatePostfix(string postfix){
    stack<int> opStack;
    
    for (int i = 0; i < postfix.length(); i++){
        char c = postfix[i];
        
        if (isdigit(c)){
            opStack.push(c - '0');
        } else {
            int operand1 = opStack.top();
            opStack.pop();
            int operand2 = opStack.top();
            opStack.pop();
            
            switch (c) {
                case '+':
                    opStack.push(operand2 + operand1);
                    break;
                case '-':
                    opStack.push(operand2 - operand1);
                    break;
                case '*':
                    opStack.push(operand2 * operand1);
                    break;
                case '/':
                    opStack.push(operand2 / operand1);
                    break;
                case '^':
                    opStack.push(pow(operand2, operand1));
                    break;
                default:
                    break;
            }
        }
    }
    return opStack.top();
}

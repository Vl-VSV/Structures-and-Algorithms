//
//  functions.hpp
//  Number 3
//
//  Created by Vlad V on 05.03.2023.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <string>

using namespace std;

bool isOperator(char c);
int getPrecedence(char op);
string infixToPostfix(string infix);
string postfixToInfix(string prefix);
string infixToPrefix(string infix);
int evaluatePostfix(string postfix);

#endif /* functions_hpp */

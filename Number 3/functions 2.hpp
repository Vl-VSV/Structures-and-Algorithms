//
//  functions 2.hpp
//  Number 3
//
//  Created by Vlad V on 05.03.2023.
//

#ifndef functions_2_hpp
#define functions_2_hpp

#include <stdio.h>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    int stack[MAX_SIZE];
    int top = -1;
    bool isEmpty();
    bool isFull();
    void push(int item);
    void pop();
    int peek();
};

int evaluatePrefix(string prefix);

#endif /* functions_2_hpp */

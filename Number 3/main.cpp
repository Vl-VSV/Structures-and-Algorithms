//
//  main.cpp
//  Number 3
//
//  Created by Vlad V on 05.03.2023.
//

#include <iostream>
#include <string>
#include <stack>

#include "functions.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    string infix = "с+b/a+(d+e-f/m*k)";
    string postfix = infixToPostfix(infix);
    cout << "Number 1" << endl << endl << "Infix: " << infix << endl << "Postfix: "<< postfix << endl << endl;
    
    return 0;
}

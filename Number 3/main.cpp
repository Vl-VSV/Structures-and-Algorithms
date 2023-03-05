//
//  main.cpp
//  Number 3
//
//  Created by Vlad V on 05.03.2023.
//

#include <iostream>
#include <string>

#include "functions.hpp"
#include "functions 2.hpp"


using namespace std;

int main(int argc, const char * argv[]) {
    
    string infix = "с+b/a+(d+e-f/m*k)";
    string postfix = infixToPostfix(infix);
    cout << "Task 1 Number 1" << endl << endl << "Infix: " << infix << endl << "Postfix: "<< postfix << endl << endl;
    
    string postfix2 = "xyz*d/+ab*cok-/--";
    string infix2 = postfixToInfix("xyz*d/+ab*cok-/--");
    cout << "Task 1 Number 2" << endl << endl << "Postfix: " << postfix2 << endl << "Infix: "<< infix2 << endl << endl;
    
    cout << "Task 1 Number 3" << endl << endl << "Infix: " << infix2 << endl << "Prefix: "<< infixToPrefix(infix2) << endl << endl;
    
    cout << "Task 1 Number 4" << endl << endl << "Postfix: " << "351+24*-126+^/+" << endl << "Result of Postfix: "<< evaluatePostfix("351+24*-126+^/+") << endl << endl;
    
    string prefix = "+-6*51/42";
    int resultOfPrefix = evaluatePrefix(prefix);
    cout << "Task 2" << endl << endl << "Prefix: " << prefix << endl << "Result Of Prefix: "<< resultOfPrefix << endl << endl;
    return 0;
}

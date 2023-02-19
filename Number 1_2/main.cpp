//
//  main.cpp
//  Number 1_2
//
//  Created by Vlad V on 18.02.2023.
//

#include <iostream>
#include "functions.hpp"
#include "structures.h"

int main(int argc, const char * argv[]) {
    ExamSheet table;
    table = fillExamSheet();
    
    while(true){
        int command;
        cout << endl << "Enter command: \n1 - Add a student's grade for the exam\n2 - Insert information about the student for the exam\n3 - Count absent students\n4 - Delete information about students who were not admitted to the exam\n5 - Display examination sheet\n0 - Exit" << endl;
        cin >> command;
        switch (command) {
            case 0:
                exit(0);
                break;
            case 1:
                add_student_grade(table);
                break;
            case 2:
                insert_student_info(table);
                break;
            case 3:
                count_students_absent(table);
                break;
            case 4:
                deleteNotAdmitted(table);
                break;
            case 5:
                displayTable(table);
                break;
            default:
                break;
        }
    }
    return 0;
}

//
//  structures.cpp
//  Number 1
//
//  Created by Vlad V on 18.02.2023.
//

#include "structures.hpp"
#include <string>

using namespace std;

struct Student {
    string surname_initials; // surname and initials of the student
    int record_book_number; // record book number of the student
    string date_of_exam; // date of receipt of the grade
    int grade; // grade received by the student
};

struct ExamSheet {
    int currentSize; // number of lines filled in the sheet
    string institute_code; // institute code
    string discipline_code; // discipline code
    string teacher_name; // surname and initials of the teacher
    Student students[MAX_STUDENTS]; // array of students who received grades
};

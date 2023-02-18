//
//  structures.h
//  Number 1_2
//
//  Created by Vlad V on 18.02.2023.
//

#ifndef structures_h
#define structures_h

#include <string>
using namespace std;

struct Student {
    string surname_initials; // surname and initials of the student
    int record_book_number; // record book number of the student
    string date_of_exam; // date of receipt of the grade
    int grade; // grade received by the student
};

struct ExamSheet {
    int currentSize = 0; // number of lines filled in the sheet
    string institute_code; // institute code
    string discipline_code; // discipline code
    string teacher_name; // surname and initials of the teacher
    Student* students;// array of students who received grades
};

#endif /* structures_h */

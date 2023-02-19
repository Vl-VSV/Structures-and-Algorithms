//
//  structures.h
//  Structures and Algorithms
//
//  Created by Vlad V on 19.02.2023.
//

#ifndef structures_h
#define structures_h

#include <string>
#include <vector>
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
    vector <Student> students; // vector of students who received grades
};

#endif /* structures_h */

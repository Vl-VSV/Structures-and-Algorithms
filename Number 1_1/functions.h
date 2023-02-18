//
//  functions.hpp
//  Number 1
//
//  Created by Vlad V on 18.02.2023.
//

#ifndef functions_h
#define functions_h

#include <stdio.h>
#include "structures.h"

ExamSheet SortStudents(ExamSheet sheet);
Student fillStudent();
ExamSheet fillExamSheet();
void displayTable(ExamSheet sheet);
void count_students_absent(ExamSheet sheet);
void add_student_grade(ExamSheet& sheet);
void insert_student_info(ExamSheet& sheet);
void deleteNotAdmitted(ExamSheet& sheet);

#endif /* functions_h */

//
//  main.cpp
//  Number 1
//
//  Created by Vlad V on 15.02.2023.
//

#include <iostream>
#include <string>
#include "structures.h"
#include "functions.h"

using namespace std;



int main(int argc, const char * argv[]) {
    ExamSheet table;
    Student student1, student2, student3;
    
    table.currentSize =3;
    table.discipline_code = "12";
    table.institute_code = "1345";
    table.teacher_name = "Yagid M A";
    
    student1.surname_initials = "Voronin V S";
    student1.record_book_number = 5674;
    student1.date_of_exam = "14.03.2023";
    student1.grade = 6;
    
    student2.surname_initials = "Bashirov M M";
    student2.record_book_number = 1234;
    student2.date_of_exam = "15.03.2023";
    student2.grade = 3;
    
    student3.surname_initials = " M M";
    student3.record_book_number = 3432;
    student3.date_of_exam = "15.03.2023";
    student3.grade = 6;
    
    table.students[0] = student1;
    table.students[1] = student2;
    table.students[2] = student3;
    
    
    displayTable(table);
    deleteNotAdmitted(table);
    displayTable(table);
    return 0;
}

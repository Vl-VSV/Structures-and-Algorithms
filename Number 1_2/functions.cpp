//
//  functions.cpp
//  Number 1_2
//
//  Created by Vlad V on 18.02.2023.
//

#include <iostream>
#include <iomanip>
#include "functions.hpp"
#include "structures.h"

using namespace std;

ExamSheet SortStudents(ExamSheet sheet)
{
    Student tmp;
    for(int i = 0; i < sheet.currentSize; i++){
        for(int j = (sheet.currentSize - 1); j >= (i+1); j--){
            if(sheet.students[j].record_book_number < sheet.students[j-1].record_book_number) {
                tmp = sheet.students[j];
                sheet.students[j] = sheet.students[j-1];
                sheet.students[j-1] = tmp;
            }
        }
    }
    return sheet;
}

Student fillStudent() {
    Student student;
    cout << endl << "Enter Surname and Initials: ";
    cin.ignore();
    getline(cin, student.surname_initials);
    
    cout << "Enter record book number: ";
    cin >> student.record_book_number;
    
    cout << "Enter date of receipt of the grade: ";
    cin >> student.date_of_exam;
    
    cout << "Enter grade: ";
    cin >> student.grade;
    return student;
}

ExamSheet fillExamSheet() {
    ExamSheet record;
    cout << endl << "Enter institute code: ";
    cin >> record.institute_code;
    cout << "Enter discipline code: ";
    cin >> record.discipline_code;
    cout << "Enter teacher name: ";
    cin.ignore();
    getline(cin, record.teacher_name);
    cout << "Enter number of students: ";
    cin >> record.currentSize;
    record.students = new Student[record.currentSize];
    
    for (int i = 0; i < record.currentSize; i++) {
        cout << endl << "Enter information about student №" << i + 1 << endl;
        record.students[i] = fillStudent();
    }
    return record;
}

// function to output the statement by defining the structure of the document
void displayTable(ExamSheet sheet) {
    
    ExamSheet sorted_sheet = SortStudents(sheet);
    
    cout << endl << "Institute Code: " << sorted_sheet.institute_code << endl;
    cout << "Discipline Code: " << sorted_sheet.discipline_code << endl;
    cout << "Teacher Name: " << sorted_sheet.teacher_name << endl;
    cout << "Information about students:" << endl;
    
    for (int i = 0; i < sorted_sheet.currentSize; i++) {
        cout << setw(40) << left << sorted_sheet.students[i].surname_initials;
        cout << "\t\t" << sorted_sheet.students[i].record_book_number << "\t\t" << sorted_sheet.students[i].date_of_exam << "\t\t" << sorted_sheet.students[i].grade << endl;
    }
}

void count_students_absent(ExamSheet sheet) {
    int count = 0;
    for (int i = 0; i < sheet.currentSize; i++) {
        if (sheet.students[i].grade == 1) {
            count++;
        }
    }
    cout << endl << "Count absent students: " << count << endl;
}

// Add a student's grade for the exam
void add_student_grade(ExamSheet& sheet) {
    
    int record_book_num;
    cout << endl << "Enter students record book number: ";
    cin >> record_book_num;
    
    for (int i = 0; i < sheet.currentSize; i++){
        if (sheet.students[i].record_book_number == record_book_num){
            cout << endl << "Enter new grade: ";
            cin >> sheet.students[i].grade;
        }
    }
}

//Insert information about the student for the exam
void insert_student_info(ExamSheet& sheet) {
    Student student;
    student = fillStudent();
    Student* new_array = new Student[sheet.currentSize + 1];
    for (int i = 0; i < sheet.currentSize; i++){
        new_array[i] = sheet.students[i];
    }
    new_array[sheet.currentSize] = student;
    sheet.students = new_array;
    sheet.currentSize++;
    
}

// function to delete information about students who were not admitted to the exam
void deleteNotAdmitted(ExamSheet& sheet) {
    
    cout << endl << "Delete not admited students" << endl;
    
    for (int i = 0; i < sheet.currentSize; i++) {
        if (sheet.students[i].grade == 6) {
            Student* new_array = new Student[sheet.currentSize - 1];
            int new_index = 0;
            for (int j = 0; j < sheet.currentSize; j++){
                if(j != i){
                    new_array[new_index] = sheet.students[j];
                    new_index++;
                }
            }
            sheet.students = new_array;
            sheet.currentSize--;
        }
    }
}

//
//  main.cpp
//  Number 2
//
//  Created by Vlad V on 26.02.2023.
//

#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList(){
        head = nullptr;
    }
    
    void add(int data){
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }
    
    void print(){
        Node* current = head;
        while(current != nullptr){
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    void reformulate(int position) {
        if (position == 1)
            return;
        
        Node* started = head;
        Node* current = head;
        
        for(int i = 0; i < position - 2; i++){
            current = current->next;
        }
        head = current->next;
        current->next = nullptr;
        
        current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = started;
    }
    
    void insertOrdered(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (head == nullptr || data < head->data) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && data >= current->next->data) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }
    
    void removeDuplicates(){
        if (head == nullptr) {
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data == current->next->data) {
                Node* duplicate = current->next;
                current->next = duplicate->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }
    }
private:
    Node* head;
};

int main(int argc, const char * argv[]) {
    LinkedList L1;
    L1.add(5);
    L1.add(4);
    L1.add(3);
    L1.add(2);
    L1.add(1);
    L1.reformulate(3);
    L1.print();
    
    LinkedList L2;
    L2.insertOrdered(3);
    L2.insertOrdered(1);
    L2.insertOrdered(4);
    L2.insertOrdered(2);
    L2.insertOrdered(5);
    L2.insertOrdered(1);
    L2.insertOrdered(4);
    L2.insertOrdered(3);
    L2.print();
    L2.removeDuplicates();
    L2.print();
    
    return 0;
}

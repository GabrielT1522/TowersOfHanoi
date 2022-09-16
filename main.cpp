// CSCE 3301 - Algorithms and Data Structures
// main.cpp
// TowersOfHanoi
//
// Created by Gabriel Torres on 9/12/22.

#include <iostream>
using namespace std;

// Create Node Link
class Node{
public:
    int element;
    Node* next;
};

// Create Linked List based Stack
class LinkedListStack{
public:
    LinkedListStack(){
        head = new Node;
        tail = new Node;
        head->next = tail;
        count = 0;
    }
    void push(int input){
        Node* newNode = new Node();
        newNode->element = input;
        newNode->next = head;
        head = newNode;
        count++;
    }
    int pop(){
        if (empty()){
            cout << "Can not pop. Stack is empty." << endl;
            exit(0);
        }
        int nodeElement = head->element;
        Node* tempNode = head;
        head = head->next;

        delete(tempNode);
        count--;
        return nodeElement;
    }

    int top(){
        return head->element;
    }
    bool empty(){
        if (count==0)
            return true;
        else
            return false;
    }
    int size(){
        return count;
    }
    void display(){
        if (empty()){
            cout << "Can not display. Stack is empty." << endl;
            return;
        }

        Node *tempNode = head;
        while (tempNode != tail){
            cout << tempNode->element << " >< ";
            tempNode = tempNode->next;
        }
        cout << endl;
    }

private:
    Node* head;
    Node* tail;
    int count;
};

// Main Program - Towers of Hanoi
int main() {
    LinkedListStack stack;

    stack.push(5);
    stack.push(9);
    stack.push(7);
    stack.push(9);
    stack.push(10);
    cout << "Current stack size: " << stack.size() << endl;
    stack.display();
    stack.pop();
    stack.pop();
    cout << "Current stack size: " << stack.size() << endl;
    cout << "Current top: " << stack.top() << endl;
    stack.display();

    return 0;
}

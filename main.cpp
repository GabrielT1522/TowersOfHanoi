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
    char element;
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
    void push(char input){
        Node* newNode = new Node();
        newNode->element = input;
        newNode->next = head;
        head = newNode;
        count++;
    }
    char pop(){
        if (empty()){
            cout << "Can not pop. Stack is empty." << endl;
            exit(0);
        }
        char nodeElement = head->element;
        Node* tempNode = head;
        head = head->next;

        delete(tempNode);
        count--;
        return nodeElement;
    }

    char top(){
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
        while (tempNode != tail-1){
            cout << tempNode->element << endl;
            tempNode = tempNode->next;
        }
        //cout << endl;
    }

private:
    Node* head;
    Node* tail;
    int count;
};

class TowersOfHanoi{
private:
    LinkedListStack stack1;
    LinkedListStack stack2;
    LinkedListStack stack3;
    int moves;
public:
    TowersOfHanoi(){
        stack1.push('-');
        stack1.push('3');
        stack1.push('2');
        stack1.push('1');

        stack2.push('-');
        stack3.push('-');
        moves = 0;
    }

    void moveDisk(){
        stack2.push(stack1.pop());
        moves++;
    }

    void displayTowers(){
        cout << "Towers as of " << moves << " moves.\n";
        cout << "Tower 1:\n";
        stack1.display();

        cout << "Tower 2:\n";
        stack2.display();

        cout << "Tower 3:\n";
        stack3.display();
    }

};

// Main Program - Towers of Hanoi
int main() {
    TowersOfHanoi game;
    game.displayTowers();
    game.moveDisk();
    game.displayTowers();









    /*LinkedListStack stack1;
    LinkedListStack stack2;
    LinkedListStack stack3;

    stack1.push(3);
    stack1.push(2);
    stack1.push(1);

    stack1.push(1);
    stack1.push(2);
    stack1.push(1);
    cout << "Current stack1 size: " << stack1.size() << endl;
    stack1.display();
    cout << "Current stack1 size: " << stack1.size() << endl;
    stack1.pop();
    cout << "Top " << stack1.top() << endl;
    cout << "Popped stack" << stack1.pop() << endl;
    stack1.pop();
    cout << "Current stack1 size: " << stack1.size() << endl;
    cout << "Current top: " << stack1.top() << endl;
    stack1.display();*/

    return 0;
}

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
            exit(1);
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
        while (tempNode != tail-1){
            cout << tempNode->element << endl;
            tempNode = tempNode->next;
        }
    }

private:
    Node* head;
    Node* tail;
    int count;
};

// Towers of Hanoi Game Class
class TowersOfHanoi{
private:
    LinkedListStack stack1;
    LinkedListStack stack2;
    LinkedListStack stack3;
    int moves;
public:
    TowersOfHanoi(){
        stack1.push(3);
        stack1.push(2);
        stack1.push(1);
        moves = 0;
    }

    void moveDisk(int fromStack, int toStack){
        switch (fromStack) {
            case 1:
                switch (toStack){
                    case 2:
                        if (stack1.top() > stack2.top() && !stack2.empty()){
                            cout << "Invalid move. No larger disk may be placed on top of a smaller disk.\n";
                            break;
                        }
                        stack2.push(stack1.pop());
                        moves++;
                        break;
                    case 3:
                        if (stack1.top() > stack3.top() && !stack3.empty()){
                            cout << "Invalid move. No larger disk may be placed on top of a smaller disk.\n";
                            break;
                        }
                        stack3.push(stack1.pop());
                        moves++;
                        break;
                    default:
                        cout << "Invalid move.";
                        break;
                }
                break;
            case 2:
                switch (toStack){
                    case 1:
                        if (stack2.top() > stack1.top() && !stack1.empty()){
                            cout << "Invalid move. No larger disk may be placed on top of a smaller disk.\n";
                            break;
                        }
                        stack1.push(stack2.pop());
                        moves++;
                        break;
                    case 3:
                        if (stack2.top() > stack3.top() && !stack3.empty()){
                            cout << "Invalid move. No larger disk may be placed on top of a smaller disk.\n";
                            break;
                        }
                        stack3.push(stack2.pop());
                        moves++;
                        break;
                    default:
                        cout << "Invalid move.";
                        break;
                }
                break;
            case 3:
                switch (toStack){
                    case 1:
                        if (stack3.top() > stack1.top() && !stack1.empty()){
                            cout << "Invalid move. No larger disk may be placed on top of a smaller disk.\n";
                            break;
                        }
                        stack1.push(stack3.pop());
                        moves++;
                        break;
                    case 2:
                        if (stack3.top() > stack2.top() && !stack2.empty()){
                            cout << "Invalid move. No larger disk may be placed on top of a smaller disk.\n";
                            break;
                        }
                        stack2.push(stack3.pop());
                        moves++;
                        break;
                    default:
                        cout << "Invalid move.";
                        break;
                }
                break;
            default:
                break;
        }

    }

    bool win(){
        if (stack2.size()==3 && stack2.top()==1){
            displayTowers();
            cout << "Congratulations, You Win!";
            return true;
        } else if (stack3.size()==3 && stack3.top()==1){
            displayTowers();
            cout << "Congratulations, You Win!";
            return true;
        }else
            return false;
    }

    void displayTowers(){
        cout << "Towers as of " << moves << " moves.\n";
        cout << "Tower 1:\n";
        if (stack1.empty())
            cout << "|\n";
        else
            stack1.display();

        cout << "Tower 2:\n";
        if (stack2.empty())
            cout << "|\n";
        else
            stack2.display();

        cout << "Tower 3:\n";
        if (stack3.empty())
            cout << "|\n";
        else
            stack3.display();
    }
};

// Main Program - Towers of Hanoi
int main() {
    TowersOfHanoi game;
    cout << "Welcome to a game of Towers of Hanoi!\n";

    while (!game.win()) {
        int toStack, fromStack;
        game.displayTowers();

        cout << "\nMove disk from tower number: ";
        cin >> fromStack;
        cout << "Move disk to tower number: ";
        cin >> toStack;
        game.moveDisk(fromStack, toStack);
    }

    return 0;
}

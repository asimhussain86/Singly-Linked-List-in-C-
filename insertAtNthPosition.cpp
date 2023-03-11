#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor to set data and next pointer
    Node(int value) {
        data = value;
        next = NULL;
    }
};

Node* head = NULL;

void insert(int number, int position) {
    Node* temp1 = new Node(number);

    if (position == 1) {
        temp1->next = head;
        head = temp1;
    }
    else {
        Node* temp2 = head;
        for (int i = 1; i < position - 1 && temp2 != NULL; i++) {
            temp2 = temp2->next;
        }
        if (temp2 != NULL) {
            temp1->next = temp2->next;
            temp2->next = temp1;
        }
        else {
            cout << "Error: position out of range" << endl;
        }
    }
}

void print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    insert(1, 1);
    insert(3, 2);
    insert(5, 3);
    insert(7, 4);
    insert(2,2); //insertion at a specific postion
    print();
    return 0;
}

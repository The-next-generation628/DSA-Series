#include <iostream>
using namespace std;

class DNode {
public:
    int data;
    DNode* prev;
    DNode* next;

    DNode(int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList {
private:
    DNode* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int value) {
        DNode* newNode = new DNode(value);
        if (head == NULL) {
            head = newNode;
            return;
        }

        DNode* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Delete by value
    void deleteNode(int value) {
        DNode* temp = head;

        while (temp != NULL && temp->data != value)
            temp = temp->next;

        if (temp == NULL) {
            cout << "Value not found!" << endl;
            return;
        }

        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        delete temp;
    }

    // Display forward
    void displayForward() {
        DNode* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Example usage
int main() {
    DoublyLinkedList dll;
    dll.insert(10);
    dll.insert(20);
    dll.insert(30);
    dll.displayForward();
    dll.deleteNode(20);
    dll.displayForward();
    return 0;
}



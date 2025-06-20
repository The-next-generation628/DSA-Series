#include<iostream>
using namespace std;
class Node {
public:
// Node class to represent each element in the linked list
    int data;
    Node* next;
    
    Node(int val) {
        data = val;
        next = nullptr;
    }
};
class LinkedList {
    public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }
    // Function to insert a new node at the beginning of the linked list
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    // Function to insert a new node at the end of the linked list
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    // Function to insert a new node at a specific position in the linked list
    void insertanywhere(int val, int position) {
        Node* newNode = new Node(val);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Position out of bounds" << endl;
            delete newNode;
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    // function to search for a key in the linked list
    // Returns true if the key is found, false otherwise
        bool search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key)
                return true;
            temp = temp->next;
        }
        return false;
    }
    //  Delete from beginning
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is already empty." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    //  Delete from end
    void deleteFromEnd() {
        if (!head) {
            cout << "List is already empty." << endl;
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    //  Delete from specific position (0-based index)
    void deleteFromPosition(int pos) {
        if (!head) {
            cout << "List is already empty." << endl;
            return;
        }
        if (pos == 0) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp->next; i++)
            temp = temp->next;

        if (!temp->next) {
            cout << "Position out of bounds." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }
    // Function to display or traversethe linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr" << endl;
    }
};
int main() {
    cout << "Linked List Insertion Example" << endl;
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtEnd(30);
    list.insertanywhere(25, 2);
    
    cout << "Linked List: ";
    list.display();
    // Searching for a key in the linked list
    if (list.search(20)) {
        cout << "Key 20 found in the linked list." << endl;
    } else {
        cout << "Key 20 not found in the linked list." << endl;
    }
    if (list.search(22)) {
        cout << "Key 22 found in the linked list." << endl;
    } else {
        cout << "Key 22 not found in the linked list." << endl;
    }
    
    // Deleting nodes from the linked list
    list.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    list.display();
    list.deleteFromEnd();
    cout << "After deleting from end: ";
    list.display();
    list.deleteFromPosition(1);
    cout << "After deleting from position 1: ";
    list.display();
    return 0;
}



#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert at end
    void insert(int value) {
        Node* newNode = new Node(value);
        if (head == NULL) {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    // Delete a node by value
    void deleteNode(int value) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* current = head;
        Node* prev = NULL;

        // If the node to delete is the head node
        if (head->data == value) {
            // Only one node
            if (head->next == head) {
                delete head;
                head = NULL;
                return;
            }

            // Find the last node to update its next
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;

            temp->next = head->next;
            Node* del = head;
            head = head->next;
            delete del;
            return;
        }

        // Delete other than head
        do {
            prev = current;
            current = current->next;
            if (current->data == value) {
                prev->next = current->next;
                delete current;
                return;
            }
        } while (current != head);

        cout << "Value not found!" << endl;
    }

    // Display the list
    void display() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)" << endl;
    }
};

// Example usage
int main() {
    CircularLinkedList cll;
    cll.insert(10);
    cll.insert(20);
    cll.insert(30);
    cll.display();
    cll.deleteNode(20);
    cll.display();
    cll.deleteNode(10);
    cll.display();
    cll.deleteNode(30);
    cll.display();
    return 0;
}

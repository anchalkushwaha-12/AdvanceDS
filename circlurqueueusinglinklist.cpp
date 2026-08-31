#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

// ENQUEUE
void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;

    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;
    }
    else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    cout << value << " inserted into queue." << endl;
}

// DEQUEUE
void dequeue() {
    if (front == NULL) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    // Only one node
    if (front == rear) {
        cout << front->data << " deleted from queue." << endl;

        delete front;
        front = rear = NULL;
    }
    else {
        Node* temp = front;

        cout << front->data << " deleted from queue." << endl;

        front = front->next;
        rear->next = front;

        delete temp;
    }
}

// PEEK
void peek() {
    if (front == NULL) {
        cout << "Queue is Empty!" << endl;
    }
    else {
        cout << "Front element: " << front->data << endl;
    }
}

// DISPLAY
void display() {
    if (front == NULL) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    Node* temp = front;

    cout << "Circular Queue: ";

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);

    cout << endl;
}

int main() {
    int choice, value;

    do {
        cout << "\n----- CIRCULAR QUEUE -----" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Program terminated." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
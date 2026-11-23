#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Circular Queue class
class CircularQueue {
private:
    Node* front;
    Node* rear;

public:

    // Constructor
    CircularQueue() {
        front = NULL;
        rear = NULL;
    }

    // ENQUEUE
    void enqueue(int value) {

        Node* newNode = new Node(value);

        // Queue is empty
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

        // Queue is empty
        if (front == NULL) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        // Only one node
        if (front == rear) {

            cout << front->data << " deleted from queue." << endl;

            delete front;

            front = NULL;
            rear = NULL;
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
            cout << "Front element: "
                 << front->data << endl;
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
};

// Main function
int main() {

    CircularQueue q;

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

                q.enqueue(value);
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.peek();
                break;

            case 4:
                q.display();
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
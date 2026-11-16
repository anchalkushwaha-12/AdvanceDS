#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// ENQUEUE
void enqueue(int value) {

    // Queue is full
    if ((rear + 1) % SIZE == front) {
        cout << "Queue is Full!" << endl;
        return;
    }

    // First element
    if (front == -1) {
        front = 0;
        rear = 0;
    }
    else {
        rear = (rear + 1) % SIZE;
    }

    queue[rear] = value;

    cout << value << " inserted into queue." << endl;
}

// DEQUEUE
void dequeue() {

    // Queue is empty
    if (front == -1) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << queue[front] << " deleted from queue." << endl;

    // Only one element
    if (front == rear) {
        front = -1;
        rear = -1;
    }
    else {
        front = (front + 1) % SIZE;
    }
}

// PEEK
void peek() {

    if (front == -1) {
        cout << "Queue is Empty!" << endl;
    }
    else {
        cout << "Front element: " << queue[front] << endl;
    }
}

// DISPLAY
void display() {

    if (front == -1) {
        cout << "Queue is Empty!" << endl;
        return;
    }

    cout << "Circular Queue: ";

    int i = front;

    while (true) {
        cout << queue[i] << " ";

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

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
#include <iostream>
using namespace std;

#define SIZE 5   // size of circular queue

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is full
    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1)));
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Insert element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << value << endl;
            return;
        }
        if (front == -1) { // first element
            front = rear = 0;
        } else if (rear == SIZE - 1 && front != 0) {
            rear = 0; // wrap around
        } else {
            rear++;
        }
        arr[rear] = value;
        cout << value << " inserted into queue." << endl;
    }

    // Delete element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Cannot remove element." << endl;
            return;
        }
        cout << arr[front] << " removed from queue." << endl;

        if (front == rear) {
            // queue becomes empty
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0; // wrap around
        } else {
            front++;
        }
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++)
                cout << arr[i] << " ";
        } else {
            for (int i = front; i < SIZE; i++)
                cout << arr[i] << " ";
            for (int i = 0; i <= rear; i++)
                cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50); // full now
    cq.display();

    cq.dequeue();
    cq.dequeue();
    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);
    cq.display();

    return 0;
}

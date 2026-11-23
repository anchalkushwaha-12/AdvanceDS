#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

int main() {
    Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;

    // Allocate 3 nodes
    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = nullptr;

    cout << "Number of nodes in the linked list: "
         << countNodes(head) << endl;
    delete head;
    delete second;
    delete third;

    return 0;
}
//height of binary tree
//count leaf nodes in binary tree
//count of nodes in binary tree
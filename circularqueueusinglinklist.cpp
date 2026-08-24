#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;};
    
class Queue{
    Node *front, *rear;
public:
    Queue(){
        front = rear = nullptr;
    }
};
void
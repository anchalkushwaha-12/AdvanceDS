#include<iostream>
using namespace std;
 
class Node{
    public:
    int data;
    Node *next;
    Node(int val){
        data = val;
        next = nullptr;
    }
    };
    Node *front, *rear;
    bool isEmpty(){
        return front == nullptr;
    }
    void traverse(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        Node *temp = front;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
        cout<<"Front = "<<front->data<<", Rear = "<<rear->data<<endl;
    }
        void enqueue(int val){
            Node *newNode = new Node(val);
            if(isEmpty()){
                front = rear = newNode;
            }
            else{
                rear->next = newNode;
                rear = newNode;
            }
        }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        int val = front->data;
        Node *temp = front;
        front = front->next;
        delete temp;
        if(front == nullptr){
            rear = nullptr;
        }
        return val;
    }
    
    int main(){
        front = rear = nullptr;
        int ch, info;
        do{
            cout<<"\n1> Enqueue";
            cout<<"\n2> Dequeue";
            cout<<"\n3> Traverse";
            cout<<"\n4> IsEmpty";
            cout<<"\n5> Exit";
            cout<<"\nEnter your choice: ";
            cin>>ch;
            switch(ch){
                case 1:
                    cout<<"Enter info: ";
                    cin>>info;
                    enqueue(info);
                    break;
                case 2:
                    info = dequeue();
                    if(info != -1){
                        cout<<"Removed element: "<<info<<endl;
                    }
                    break;
                case 3:
                    traverse();
                    break;
                case 4:
                    cout<<"The queue is "<<(isEmpty() ? "Empty" : "Not Empty")<<endl;
                    break;
                case 5:
                    cout<<"Exiting..."<<endl;
                    break;
                default:
                    cout<<"Invalid choice"<<endl;
            }
        }while(ch != 5);
        return 0;
    }
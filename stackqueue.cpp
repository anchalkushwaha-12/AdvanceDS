#include <iostream>
#define SIZE 10
using namespace std;

class Queue{
    public:
    int data[SIZE];
    int front, rear;
    
    void initialize()
    {
        front = rear = -1;
    }
    
    bool isEmpty()
    {
        return front == -1;
    }
    
    bool isFull()
    {
        return rear == SIZE - 1;
    }
    
    void enqueue(int info)
    {
        if (rear == SIZE - 1)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        if (front == -1)
        front =  front + 1;
        
        rear = rear + 1;
        data[rear] = info;
    }
    
    int dequeue()
    {
        int item;
        
        if (front == -1)
        {
            cout<<endl<<"Queue is empty"<<endl;
            return -1;
        }
         
         item = data[front];
         
         if(front == rear)
         front = rear = -1;
         else
         front = front + 1;
         return item;
    }
    
    void traverse()
    {
        if(isEmpty())
        {
            cout<<"Queue is Empty"<<endl;
            return;
            }
            
            for(int i = front; i <= rear; i++)
            {
                cout<<data[i]<<" ";
            }
            cout<<endl;
    }
};
  
  int main(){
      Queue Q;
      Q.initialize();
      
      int ch,info;
      
      do{
          cout<<"\n1> Enqueue";
          cout<<"\n2> Dequeue";
          cout<<"\n3> Traverse";
          cout<<"\n4> IsEmpty";
          cout<<"\n5> Isfull";
          cout<<"\n6> Exit";
          cout<<"\nEnter your choice: ";
          
          cin>>ch;
          
          switch(ch)
          {
              case 1:
              cout<<"Enter info: ";
              cin>>info;
              
              Q.enqueue(info);
              
              cout<<"Front = "<<Q.front<<", Rear = "<<Q.rear<<endl;
              break;
              
              case 2:
              info = Q.dequeue();
              
              if(info != -1)
              {
                  cout<<"Removed element: "<<info<<endl;
              }
              
              cout<<"front = "<<Q.front<<", Rear = "<<Q.rear<<endl;
              break;
              
              case 3:
              Q.traverse();
              
              cout<<"front = "<<Q.front<<", Rear = "<<Q.rear<<endl;
              break;
              
              case 4:
              cout<<"The queue is "<<(Q.isEmpty() ? "Empty" : "Not Empty")<<endl;
              break;
              
              case 5:
              cout<<"The queue is "<<(Q.isFull() ? "Full" : "Not Full")<<endl;
              break;
              
              case 6:
              cout<<"This code is executed by Alisha with Roll No. 2503201000151"<<endl;
              break;
              
              default:
              cout<<"Invalid Choice! Try again"<<endl;
          } 
      }
      while(ch != 6);
      return 0;
  }
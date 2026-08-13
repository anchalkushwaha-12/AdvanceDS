#include <iostream>
using namespace std;
int n=5;
int stack[5];
int top=-1;

bool isEMPTY(){
    return top<=-1;
}

bool isFULL(){
    return top>=n-1;
}
void push(int ITEM){
    if(isFULL())
{
    cout<<"overflow"<<endl;
}    
else
{
    top++;
    stack[top]=ITEM;
}
}
void pop(){
    if (isEMPTY())
    {
        cout<<"Underflow"<<endl;
    }
    else{
        cout<<"The element is "<<stack[top]<<endl;
        top--;
    }
}
void traverse()
{
    int i;
    if(!isEMPTY())
    {
        cout<<"stack elements are: ";
        for (i=top; i>=0; i--)
        {
            cout<<stack[i]<<" ";
        }
        cout<<endl;
        cout<<"top element is: "<<stack[top]<<endl;
    }
    else
    {
        cout<<"stack is empty"<<endl;
    }
 }
 int main(){
     int ch , ITEM;
     
     cout<<"1) PUsh"<<endl;
     cout<<"2) Pop"<<endl;
     cout<<"3) traverse"<<endl;
     cout<<"4) Exit"<<endl;
     
     do{
         cout<<"enter choice: ";
         cin>>ch;
         switch(ch){
             case 1:
             {
                 cout<<"Enter item: "<<endl;
                 cin>>ITEM;
                 push(ITEM);
                 break;
             }
             case 2:
             {
                 pop();
                 break;
             }
             case 3:
             {
                 traverse();
                  break;
             }
             case 4:
             {
                 cout<<"exit"<<endl;
                 break;
             }
             default:
             {
                 cout<<"Invalid Choice"<<endl;
             }
         }
     }while(ch !=4);
             
    return 0;
}
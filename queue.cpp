#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    Node(int value){
        data=value;
        next=NULL;
    }
};
class Queue{
    Node *front;
    Node *rear;

    public:
    Queue(){
        front=NULL;
        rear=NULL;
    }
    void enqueue(int value){
        Node *newNode=new Node(value);
        if(front==NULL){
            front=rear=newNode;
        }else{
            rear->next=newNode;
            rear=newNode;

        }
    }
    void dequeue(){
        if(front==NULL){
            cout<<"empty queue"<<endl;
            return;
        }
        Node *temp=front;
        front=front->next;
        delete temp;
    }
    int peak(){
        if(front==NULL){
            cout<<"empty queue";
            return -1;
        }
        return front->data;
    }
    void display(){
        
        Node *temp=front;
        while(temp!=NULL){
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};
int main()
{
   Queue q1;
   q1.enqueue(12);
   q1.enqueue(133);
   q1.enqueue(33);
   q1.display();
   q1.dequeue();
   q1.display();
}
#include<iostream>
using namespace std;
class Node{
public:
    int data;
    Node * next;

    Node(int val){
        data=val;
        next=NULL;
    }
};
class circularlist{
    Node* head;
    Node* tail;
public:
    circularlist(){
        head=tail=NULL;
    }

    void insert(int val){
        Node *newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            newNode->next=head;
            head=newNode;
            tail->next=newNode;
        }
    }
    void insertlast(int val){
        Node *newNode= new Node(val);
        if(head==NULL){
            head=tail=newNode;
            tail->next=head;
        }else{
            tail->next=newNode;
            tail=newNode;
            tail->next=head;
        }
    }
    void display(){
        if(head==NULL){
            return;
        }
        cout<<head->data<<"  ";
        Node* temp = head->next;

        while(temp!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};

int main()
{
    circularlist cl;
    cl.insert(10);
    cl.insert(20);
    cl.insert(30);
    cl.insertlast(40);
    cl.display();
    return 0;
}
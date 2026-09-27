#include<iostream>
using namespace std;
class node{
public:
    int data;
    node * next;
    node * prev;

    node(int val){
        data=val;
        next= prev=NULL;
    }
};
class doublylist{
    node* head;
    node* tail;
public:
doublylist(){
    head=tail=NULL;
}
    void insert(int val){
        node * newNode = new node(val);
        if(head==NULL){
            head=tail=newNode;
        }else{
            newNode->next=head;
            head->prev=newNode;

            head=newNode;
        }
    }
    void insertlast(int val){
        node * newNode= new node(val);
        if(head==NULL){
            head=tail=NULL;
        }else{
            newNode->prev=tail;
            tail->next=newNode;

            tail=newNode;
        }
    }
    void removefirst(){
        if(head==NULL){
            cout<<"list is empty";
            return;
        }else{
            node *temp=head;
            head=head->next;
            head->prev=NULL;
            temp->next=NULL;
            delete temp;
        }
    }
    void removelast(){
        if(head==NULL){
            cout<<"list is empty";
            return;
        }
        node *temp=tail;
        tail=tail->prev;
        if(tail!=NULL){
            temp->prev=NULL;
        }
        tail->next=NULL;
        delete temp;
        
    }
    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    } 
};
int main(){
    doublylist dll;
    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.display();
    
    dll.insertlast(4);
    dll.display();

    dll.removelast();
    dll.display();


}
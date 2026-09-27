#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int value){
        data=value;
        next=NULL;
    }
};
class List{
    Node* head;
    Node* tail;

    public:
    List(){
        head=tail=NULL;
        }
    void insert(int value){
            Node* newNode= new Node(value);
            if(head==NULL){
                head=tail=newNode;
            }else{
                newNode->next=head;
                head=newNode;
            }
    }

    void insertlast(int value){
        Node* newNode= new Node(value);
        if(head==NULL){
            head=tail=newNode;
        }else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void removefirst(){
        if(head==NULL){
            cout<<"list is empty"<<endl;
            return;
        }else{
            Node* temp= head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    void removelast(){
        if(head==NULL){
            cout<<"list is empty"<<endl;
            return;
        }else{
            Node* temp= head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            tail->next=NULL;
        }
    }
    void insertmiddle(int value, int position){
        if(position<=0){
            cout<<"invalid position"<<endl;
            return;
        }
        if(position==1){
            insert(value);
            return;
        }
       Node* temp= head;
       for(int i=1;i<position-1;i++){
        if(temp==NULL){
            cout<<"invalid position"<<endl;
            return;
        }
        temp=temp->next;
       }
       Node* newNode= new Node(value);
       newNode->next=temp->next;
       temp->next=newNode;
    }
        void print(){
    Node* temp= head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int search(int value){
    Node* temp= head;
    int position=1;
    while(temp!=NULL){
        if(temp->data==value){
            return position;
        }
        temp=temp->next;
        position++;
    }
    return -1;
}
};
int main()
{
    List ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);

    ll.insertlast(4);

    ll.removefirst();
    ll.removelast();

    ll.insertmiddle(5,2);


    ll.print();
    cout<<ll.search(5)<<endl;

    return 0;
}
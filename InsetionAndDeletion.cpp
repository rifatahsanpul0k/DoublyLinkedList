//Not Circular LinkedList

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int d) : data(d), next(nullptr), prev(nullptr) {}
};

void insertHead(Node *&head, int data)
{
    Node *newNode = new Node(data); 
    newNode->next = head;

    if (head != nullptr)
    {                        
        head->prev = newNode; 
    }
    head = newNode;
}
void insertTail(Node *head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    Node *tail;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
}
void insertAfter(Node* prevNode, int data){
    if(prevNode==nullptr) //prevNode doesn't exist
    return;
    Node* newNode = new Node(data);
    prevNode->next = newNode;
    newNode->prev = prevNode;
    if(newNode->next != nullptr)
    newNode->next->prev = newNode;

}

void deleteHead(Node* head){
    if(head == nullptr) return;
    Node* temp;
    temp = head;
    head = head->next;
    if(head!=nullptr){
        head->prev = nullptr;
    }
    delete temp;
}

void deleteEnd(Node* head ){
    if(head == nullptr) return;
    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node* Tail = head;
    while(Tail->next!=nullptr){
        Tail = Tail->next;
    }
    Tail->next->prev = nullptr;
    delete Tail;
}

void main(){

}
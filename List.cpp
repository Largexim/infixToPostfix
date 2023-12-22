#include <iostream>
#include "List.h"
using namespace std;

List::List() {
    head = nullptr;
    length = 0;
}
List::List(const string& input){
    head = new node;
    head->data = input;
    head->next= nullptr;
    length = 1;
}
List::List(const char& input){
    head = nullptr;
    head->data = input;
    head->next= nullptr;
    length = 1;
}
List::List(const List& input){
    head = nullptr;
    length = 0;

    node* inputPtr = input.head;

    while (inputPtr != nullptr) {
        append(inputPtr->data);
        inputPtr = inputPtr->next;
    }
}
void List::append(const string& input){
    if(length==0){
        head = new node;
        head->data = input;
        head->next = nullptr;
        length++;
    }
    else {
        node *newNode = new node;
        newNode->data = input;
        newNode->next = nullptr;

        node *p = head;
        while (p->next != nullptr)
            p = p->next;

        p->next = newNode;

        length++;
    }
}
void List::append(const char& input){
    if(length==0){
        head = new node;
        head->data = input;
        head->next = nullptr;
        length++;
        return;
    }
    node * newNode = new node;
    newNode->data = input;
    newNode->next = nullptr;

    node * p = head;
    while(p->next!= nullptr)
        p = p->next;

    p->next = newNode;

    length++;
}
void List::insert(const string& input){
    node * p = head;
    while(p->next!= nullptr)
        p = p->next;

    p->data = input;
}
void List::insert(const char& input){
    node * p = head;
    while(p->next!= nullptr)
        p = p->next;

    p->data = input;
}
void List::insert(const int& index,const string& input){
    node* p = head;
    for(int i=0 ; i<index ; i++)
        p=p->next;
    p->data = input;
}
string List::pop(){
    if(length==1){
        string returning = head->data;
        head = nullptr;
        length--;
        return returning;
    }

    node * p = head;
    while(p->next->next!= nullptr)
        p = p->next;

    string returning = p->next->data;
    p->next = nullptr;
    length--;
    return returning;
}
string List::pfd(){
    if(length==1){
        string returning = head->data;
        head = nullptr;
        length--;
        return returning;
    }
    string returning = head->data;
    head=head->next;
    length--;
    return returning;
}
string List::pick(){
    if(length==1)
        return head->data;
    node * p = head;
    while(p->next!= nullptr)
        p = p->next;
    return p->data;
}
string List::pwi(const int& input) const{
    node * p = head;
    for (int i=0 ;i<input ; i++)
        p=p->next;
    return p->data;
}
string List::pickFromDown(){
    return head->data;
}
unsigned int List::getLengths() const{
    return length;
}
void List::print() const{
    if(isEmpty())
        cout<<"[EMPTY]";
    else {
        cout << "[";
        for (int i = 0; i < length; i++) {
            cout << " " << pwi(i) << " ";
        }
        cout << "]";
    }
    cout<<endl;
}
bool List::isEmpty() const{
    if(length==0)
        return true;
    return false;
}
List& List::operator= (const List& input){
    if (this != &input) {
        node* current = head;
        while (current != nullptr) {
            node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        length = 0;

        node* inputPtr = input.head;

        while (inputPtr != nullptr) {
            append(inputPtr->data);
            inputPtr = inputPtr->next;
        }
    }
    return *this;
}
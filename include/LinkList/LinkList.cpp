#include <cstdlib>
#include <iostream>
#include<new>
#include<stdexcept>
template <typename T>
LinkList<T>::LinkList():head(nullptr),tail(nullptr),size(0){}
template<typename T>
LinkList<T>::~LinkList(){
  Node* temp=head;
  while(temp!=nullptr){
    Node* temporary=temp;
    temp=temp->next;
    (*temporary).~Node();
    free(temporary);
  }
}
template<typename T>
void LinkList<T>::insertFront(const T& value){
  Node* newNode=(Node*)malloc(sizeof(Node));
  if(newNode==nullptr){
    throw std::bad_alloc();
  }
  new(newNode)Node(value);
  if(head==nullptr&&tail==nullptr){ 
    head=newNode;
    tail=newNode;
  }else{
    newNode->next=head;
    head=newNode;
  }
  ++size;
}
template<typename T>
void LinkList<T>::insertBack(const T& value){
    Node* newNode=(Node*)malloc(sizeof(Node));
  if(newNode==nullptr){
    throw std::bad_alloc();
  }
  new(newNode)Node(value);
  if(head==nullptr&&tail==nullptr){ 
    head=newNode;
    tail=newNode;
  }else{
  tail->next=newNode;
  tail=newNode;
  }
  ++size;
}
template<typename T>
void LinkList<T>::insert(int index,const T& value){
  if(index<0||index>size){
    throw std::out_of_range("Invalid Index");
  }
  if(index==0){
    insertFront(value);
    return;
  }
  if(index==size){
    insertBack(value);
    return;
  }
  Node* newNode=(Node*)malloc(sizeof(Node));
  if(newNode==nullptr){
    throw std::bad_alloc();
  }
  new(newNode)Node(value);
  int i=1;
  Node* temp=head;
  while(i<index){
    temp=temp->next;
    ++i;
  }
  newNode->next=temp->next;
  temp->next=newNode;
  size++;
}
template<typename T>
void LinkList<T>::deleteFront(){
  if(size==0){return;}
  if(size==1){
    (*head).~Node();
    free(head);
    head=nullptr;
    tail=nullptr;
    --size;
    return;
  }
  Node* temp=head;
  head=head->next;
  (*temp).~Node();
  free(temp);
  --size;
}
template<typename T>
void LinkList<T>::deleteBack(){
  if(size==0){return;}
  if(size==1){
    (*tail).~Node();
    free(tail);
    head=nullptr;
    tail=nullptr;
    --size;
    return;   
  }
  Node* temp=head;
  while(temp->next->next!=nullptr){
    temp=temp->next;
  }
  Node * temporary=temp->next;
  tail=temp;
  tail->next=nullptr;
  (*temporary).~Node();
  free(temporary);
  --size;
}
template<typename T>
void LinkList<T>::print() const{
  Node* temp=head;
  while(temp!=nullptr){
    std::cout<<temp->data<<"\n";
    temp=temp->next;
  }
}
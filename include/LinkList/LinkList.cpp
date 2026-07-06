#include <cstdlib>
#include <iostream>
#include<new>
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
}
template<typename T>
void LinkList<T>::print() const{
  Node* temp=head;
  while(temp!=nullptr){
    std::cout<<temp->data<<"\n";
    temp=temp->next;
  }
}
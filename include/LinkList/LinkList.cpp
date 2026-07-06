#include <cstdlib>
#include <iostream>
#include<new>
template <typename T>
LinkList<T>::LinkList(){
  this->head=nullptr;
  this->tail=nullptr;
  this->size=0;
}
template<typename T>
void LinkList<T>::insertFront(T value){
  Node* newNode=(Node*)malloc(sizeof(Node));
  new(newNode)Node(value);
  if(head==nullptr&&tail==nullptr){ 
    head=newNode;
    tail=newNode;
  }else{
    newNode->next=head;
    head=newNode;
  }
  size++;
}
template<typename T>
void LinkList<T>::print(){
  Node* temp=head;
  while(temp!=nullptr){
    std::cout<<temp->data<<" ";
    temp=temp->next;
  }
}
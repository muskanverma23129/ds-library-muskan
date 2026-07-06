#ifndef LINKLIST_H
#define LINKLIST_H
template <typename T>
class LinkList{
  private:
  int size;
  struct Node{
    T data;
    Node* next;
    Node(T data){
      this->data=data;
      next=nullptr;
    }
  };
  Node* head;
  Node* tail;
  public:
  LinkList();
  void insertFront(T value);
  void print();
};
#include "LinkList.cpp"
#endif
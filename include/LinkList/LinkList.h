#ifndef LINKLIST_H
#define LINKLIST_H
template <typename T>
class LinkList{
  private:
  int size;
  struct Node{
    T data;
    Node* next;
    Node(const T& data){
      this->data=data;
      next=nullptr;
    }
  };
  Node* head;
  Node* tail;
  public:
  LinkList();
  ~LinkList();
  LinkList(const LinkList& other);
  LinkList& operator=(const LinkList& other);
  void insertFront(const T& value);
  void insertBack(const T& value);
  void insert(int index,const T& value);
  void deleteFront();
  void deleteBack();
  void removeAt(int index);
  bool removeValue(const T& value);
  void clear();
  const T& getFront() const;
  const T& getBack() const;
  const T& get(int index) const;
  void set(int index,const T& value);
  int getSize() const;
  bool isEmpty() const;
  void print() const;

};
#include "LinkList.cpp"
#endif
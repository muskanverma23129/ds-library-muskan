#include "./HashMap.h"
#include <stdexcept>
HashMap::HashMap() : size(0), capacity(8), buckets(8)
{
  for (int i = 0; i < capacity; i++)
  {
    buckets.append(LinkList<Pair>());
  }
}
HashMap::HashMap(int capacity) : size(0), capacity(capacity), buckets(capacity)
{
  for (int i = 0; i < capacity; i++)
  {
    buckets.append(LinkList<Pair>());
  }
}
void HashMap::set(int key, std::string value)
{
  Pair p(key, value);
  int bucketno = key % capacity;
  LinkList<Pair> &temp = buckets.get(bucketno);
  // if(temp==nullptr){
  //   temp.insertFront(p);
  // }else{
  temp.insertBack(p);
  ++size;
}
std::string HashMap::get(int key)
{
  LinkList<Pair> &temp = buckets.get(key % capacity);
  int i = 0;
  // LinkList<Pair> *temporary=temp->head;
  while (i < temp.getSize())
  {
    if (temp.get(i).key == key)
    {
      return temp.get(i).value;
    }
    ++i;
  }
  throw std::invalid_argument("key doesnot exist");
}
void HashMap::print()
{
  for (int i = 0; i < capacity; i++)
  {
    LinkList<Pair> &temp = buckets.get(i);
    std::cout << "bucket" << i + 1 << "->";
    int j = 0;
    int size = temp.getSize();
    if (size == 0)
    {
      std::cout << "Empty";
    }
    else
      while (j < size)
      {
        if (j == size - 1)
          std::cout << "(" << temp.get(j).key << "," << temp.get(j).value << ")";
        else
          std::cout << "(" << temp.get(j).key << "," << temp.get(j).value << ")->";
        ++j;
      }
    // LinkList<Pair>::Node * move=temp.head;
    // while(move!=nullptr){
    //   if(move->next!=nullptr)
    //   std::cout<<move->data->value<<"->";
    //   move=move->next;
    // }
    std::cout << "\n";
  }
}
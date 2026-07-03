#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
template<typename T>
class DynamicArray{
  private:
    int size;
    int capacity;
    T* arr;
  public:
    DynamicArray();
    DynamicArray(int capacity);
    int getSize();
    int getCapacity();
    void regrow();
    void append(T data);
    void insert(int index,T data);
    T get(int index);
};
#endif
#include "DynamicArray.tpp"
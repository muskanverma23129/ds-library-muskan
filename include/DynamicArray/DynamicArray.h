#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
class DynamicArray{
  private:
    int size;
    int capacity;
    int* arr;
  public:
    DynamicArray();
    DynamicArray(int capacity);
    void regrow();
    void append(int data);
    int get(int index);
};
#endif
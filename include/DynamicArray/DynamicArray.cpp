#include "DynamicArray.h"
#include<new>//for bad_alloc exception
#include<stdexcept>//for logical error like invalid argument
#include<cstdlib>//for malloc realloc
DynamicArray ::DynamicArray()
{
  this->size = 0;
  this->capacity = 0;
  this->arr = nullptr;
}

DynamicArray::DynamicArray(int capacity)
{
  if (capacity <= 0)
  {
    throw std::invalid_argument("capacity must be positive");
  }
  this->size = 0;
  this->capacity = capacity;
  this->arr = (int *)malloc(sizeof(int) * this->capacity);
  if (this->arr == nullptr)
  {
    throw std::bad_alloc();
  }
}

void DynamicArray::regrow()
{
  int newcapacity = 2 * this->capacity;
  int *temp = (int *)realloc(this->arr,sizeof(int) * newcapacity);
  if (temp == nullptr)
  {
    throw std::bad_alloc();
  }
  else
  {
    this->arr = temp;
    this->capacity = newcapacity;
  }
}

void DynamicArray::append(int data)
{
  if (this->capacity == 0)
  {
    int newcapacity = 10;
    this->arr = (int *)malloc(sizeof(int) * newcapacity);
    if (this->arr == nullptr)
    {
      throw std::bad_alloc();
    }
    else
    {
      this->capacity = newcapacity;
    }
  }
  else if (this->size == this->capacity)
  {
    regrow();
  }
  this->arr[this->size] = data;
  this->size++;
}
int DynamicArray::get(int index)
{
  if (index < 0 || index >= size)
  {
    throw std::out_of_range("index out of range");
  }
  return this->arr[index];
}
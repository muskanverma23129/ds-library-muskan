#include<iostream>
#include "../include/DynamicArray/DynamicArray.h"
using namespace std;
int main(){
  DynamicArray<int> d;
  for(int i=1;i<=10;i++){
    d.append(10*i);
  }
  for(int i=0;i<10;i++){
    cout<<d.get(i)<<" ";
  }
  return 0;
}
#include<iostream>
#include "../include/LinkList/LinkList.h"
int main(){
  LinkList<int> l;
  for(int i=1;i<5;i++){
    l.insertFront(i*10);
  }
  l.print();
}
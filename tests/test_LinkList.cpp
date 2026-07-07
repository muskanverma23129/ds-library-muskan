#include<iostream>
#include<string>
#include "../include/LinkList/LinkList.h"
using namespace std;
int main(){
LinkList<string> l;
  // for(int i=1;i<5;i++){
  //   l.insertFront(i*10);
  // }
  l.insertBack("one");
  l.insertBack("two");
  l.insertBack("three");
  l.insertBack("four");
  l.insertBack("five");
LinkList<string> l2=l;
l.set(0,"0");
l.set(1,"1");
l.insert(2,"1.5");
 l.print();
 l2.print();
}
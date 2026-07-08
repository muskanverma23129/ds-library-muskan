#include<iostream>
#include "../include/HashMap/HashMap.h"
using namespace std;
int main(){
  HashMap h(10);
  h.set(10,"muskan1");
  h.set(20,"muskan2");
  h.set(30,"muskan3");
  h.set(40,"muskan4");
  h.set(50,"muskan5");
  h.set(11,"verma1");
  h.set(21,"verma2");
  h.set(31,"verma3");
  h.set(41,"verma4");
  h.set(51,"verma5");
  // cout<<h.get(10)<<" "<<h.get(11);
  h.print();
  return 0;
}
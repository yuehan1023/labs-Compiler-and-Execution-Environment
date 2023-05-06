/*
  - Insight. On Intel, it is much more efficient to use stdbool

*/

#include <stdbool.h>

int foo(int x){
  return !x;
}

bool foo2(bool x){
  return !x;
}


int bar(int x, int y){
  return x && y;
}

// Much shorter ASM code
bool bar2(bool x, bool y){
  return x && y;
}

// Better insruction selection
int boo(int x, int y){
  return x == 7 &&  y != 8;
}


int main(){
  return foo(7);
}

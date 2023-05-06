
extern int bar2(int x, int y);
extern int bar3(int x, int y, int z);



int foo1(int x, int y){
  return x*10 + y;
}


int main(){
  int a = foo1(2,3);
  int b = bar2(4,5);
  int c = bar3(6,7,8);
  return a + b + c;
}

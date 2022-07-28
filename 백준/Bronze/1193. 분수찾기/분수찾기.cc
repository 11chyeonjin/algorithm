#include <iostream>
using namespace std;

int main() {
  int X;
  cin >> X;

  int tmp = 1;
  int max = 0;
  while(max < X) {
    max += tmp;
    tmp++;
  }
  
  tmp -= 1;
  int a, b;
  
  if (tmp % 2) {
    a = max - X + 1;
    b = tmp + 1 - a;
  }
  else {
    a = X - max + tmp;
    b = tmp + 1 - a;
  }
  cout << a << "/" << b;
  
  return 0;
}
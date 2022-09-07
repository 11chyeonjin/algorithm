#include <iostream>
using namespace std;

long long a, B, c;

long long func(long long b) {
  if (b > 1) {
    if (b % 2 == 0) {
      return (func(b / 2) % c) * (func(b / 2) % c) % c;
    }
    else { // b 가 홀수     
      return (func(b / 2) % c) * (func(b / 2) % c) % c * a % c;
    }
  }
  else { // b 가 1
    return a;
  }
}

int main() {
  cin >> a >> B >> c;
  a = a % c;

  cout << func(B);

  return 0;
}
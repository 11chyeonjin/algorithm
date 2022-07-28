#include <iostream>
using namespace std;

int main() {
  int a, b, v;
  cin >> a >> b >> v;

  int result;

  v -= a;

  if (v % (a-b) == 0) {
    result = v / (a-b) + 1;
  }
  else {
    result = v / (a-b) + 2;
  }

  cout << result;

  return 0;
}
#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int rI = C - B;
  if (rI <= 0)
    cout << -1;
  else {
    cout << A / rI + 1;
  }

  return 0;
}
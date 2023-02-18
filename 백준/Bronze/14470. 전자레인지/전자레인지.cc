#include <iostream>
using namespace std;

int A, B;
int C, D, E;

int main() {
  cin >> A >> B;
  cin >> C >> D >> E;

  int result = 0;
  if (A < 0) {
    result += A * C * (-1);
    result += D;
    result += B * E;
  }
  else {
    result += (B - A) * E;
  }

  cout << result;

  return 0;
}
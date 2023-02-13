#include <iostream>
using namespace std;

long long a, b, c;

int main() {
  cin >> a >> b >> c;

  cout << max(a * b / c, a * c / b);

  return 0;
}
#include <iostream>
using namespace std;

int p[4];
int x, y, r;

int main() {
  for (int i = 0; i < 4; i++) {
    cin >> p[i];
  }
  cin >> x >> y >> r;

  int result = 0;
  for (int i = 0; i < 4; i++) {
    if (x == p[i])
      result = i + 1;
  }

  cout << result;

  return 0;
}
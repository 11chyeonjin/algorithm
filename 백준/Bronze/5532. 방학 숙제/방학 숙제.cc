#include <iostream>
using namespace std;

int main() {
  int L, A, B, C, D;
  cin >> L >> A >> B >> C >> D;

  int x = A / C;
  if (A % C)
    x++;
  int y = B / D;
  if (B % D)
    y++;

  cout << L - max(x, y);
  return 0;
}
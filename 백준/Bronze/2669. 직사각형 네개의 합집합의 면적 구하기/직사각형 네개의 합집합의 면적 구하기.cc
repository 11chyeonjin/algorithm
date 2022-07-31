#include <iostream>
using namespace std;

int user[101][101] = { 0 };

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int x, y, xx, yy;
  for (int k = 0; k < 4; k++) {
    cin >> x >> y >> xx >> yy;
    for (int i = x + 1; i <= xx; i++) {
      for (int j = y + 1; j <= yy; j++) {
        user[j][i] = 1;
      }
    }
  }

  int sum = 0;
  for (int i = 0; i <= 100; i++) {
    for (int j = 0; j <= 100; j++) {
      if (user[j][i])
        sum++;
    }
  }

  cout << sum;

  return 0;
}
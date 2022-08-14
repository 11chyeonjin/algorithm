#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  int M, N, x, y;
  for (int i = 0; i < T; i++) {
    cin >> M >> N >> x >> y;
    int num = 0;
    bool flag = false;
    if (M == x && N == y)
      flag = true;
    if (M == x)
      x = 0;
    if (N == y)
      y = 0;
    while(1) {
      num += x;
      if (!num)
        num += M;
      if (num % N == y) {
        cout << num << "\n";
        break;
      }
      num += (M - x);
      if (!(num % M) && !(num % N)) {
        if (!flag) {
          cout << -1 << "\n";
          break;
        }
        else {
          cout << num << "\n";
          break;
        }
      }
    }
  }

  return 0;
}
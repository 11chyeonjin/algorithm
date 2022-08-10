#include <iostream>
#include <string>
using namespace std;

int user[64][64];

bool all_same(int a, int b, int aa, int bb) {
  int tmp = user[a][b];
  if (a == aa) {
    return true;
  }
  for (int i = a; i <= aa; i++) {
    for (int j = b; j <= bb; j++) {
      if (user[i][j] != tmp) {
        return false;
      }
    }
  }
  return true;
}

void func(int a, int b, int aa, int bb) {
  int half = (aa + 1 - a) / 2;
  if (all_same(a, b, aa, bb)) {
    cout << user[a][b];
  }
  else {
    cout << '(';
    func(a, b, aa - half, bb - half);
    func(a, b + half, aa - half, bb);
    func(a + half, b, aa, bb - half);
    func(a + half, b + half, aa, bb);
    cout << ')';
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  string in;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> in;
    for (int j = 0; j < n; j++) {
      user[i][j] = in[j] - '0';
    }
  }
  
  func(0, 0, n-1, n-1);

  return 0;
}
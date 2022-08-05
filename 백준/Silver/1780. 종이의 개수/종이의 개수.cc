#include <iostream>
using namespace std;

int user[2200][2200];

int one = 0;
int zero = 0;
int minus_one = 0;

int n;

void func(int a, int b, int aa, int bb) {
  int size = aa - a + 1;
  if (size == 1) {
    if (user[a][b] == 1)
      one++;
    else if (!user[a][b])
      zero++;
    else
      minus_one++;
  }
  else {
    int flag = 0;
    int tmp = user[a][b];
    for (int i = a; i <= aa; i++) {
      for (int j = b; j <= bb; j++) {
        if (tmp != user[i][j]) {
          flag = 1;
          break;
        }
      }
      if (flag)
        break;
    }
    if (flag) {
      size = size / 3 - 1; // 사이즈를 3 으로 나누고, -1을 취함.
      func(a, b, a + size, b + size);
      func(a + size + 1, b, aa - size - 1, b + size);
      func(aa - size, b, aa, b + size);
      func(a, b + size + 1, a + size, bb - size -1);
      func(a + size + 1, b + size + 1, aa - size - 1, bb - size -1);
      func(aa - size, b + size + 1, aa, bb - size -1);
      func(a, bb - size, a + size, bb);
      func(a + size + 1, bb - size, aa - size - 1, bb);
      func(aa - size, bb - size, aa, bb);
    }
    else {
      if (tmp == 1)
        one++;
      else if (!tmp)
        zero++;
      else
        minus_one++;
    }  
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> n;
  int in;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> in;
      user[i][j] = in;
    }
  }

  func(0, 0, n-1, n-1);

  cout << minus_one << "\n" << zero << "\n" << one;

  return 0;
}
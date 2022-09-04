#include <iostream>
using namespace std;

int N;

bool user[3100][6300] = { false };

void star(int a, int b) {
  user[a][b] = true;
  user[a + 1][b - 1] = user[a + 1][b + 1] = true;
  for (int i = b - 2; i <= b + 2; i++) {
    user[a + 2][i] = true;
  }
}

void stars(int a, int b, int num) {
  int tmp = num / 2;
  if (num == 1) {
    star(a, b);
    // star(a + 3, b - 3);
    // star(a + 3, b + 3);
  }
  else {
    stars(a, b, tmp);
    stars(a + tmp * 3, b - tmp * 3, tmp);
    stars(a + tmp * 3, b + tmp * 3, tmp);
  }
}

int main() {
  cin >> N;

  int num = N / 3;

  int height, width;
  if (num == 1) {
    star(0, 2);
    height = N;
    width = 5;
  }
  else {
    stars(0, num / 2 * 5 + num / 2 - 1, num);
    height = N;
    width = num * 5 + num - 1;
  }
    
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (user[i][j])
        cout << "*";
      else
        cout << " ";
    }
    cout << "\n";
  }

  return 0;
}
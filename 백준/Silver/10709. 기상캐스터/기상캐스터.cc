#include <iostream>
#include <algorithm>
using namespace std;

int H, W;
int user[100][100];

int main() {
  cin >> H >> W;

  string in;
  for (int i = 0; i < H; i++) {
    cin >> in;
    for (int j = 0; j < W; j++) {
      if (in[j] == '.') {
        user[i][j] = -1;
      }
      else {
        user[i][j] = 0;
      }
    }
  }
  int tmp = 1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (!user[i][j]) {
        tmp = 1;
        for (int p = j + 1; p < W; p++) {
          if (!user[i][p])
            break;
          else {
            user[i][p] = tmp;
            tmp++;
          }
        }
      }
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cout << user[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
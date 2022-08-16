#include <iostream>
#include <cstring>
using namespace std;

int w, h;

int user[50][50];
bool check[50][50];

int da[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };
int db[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };

void dfs(int a, int b) {
  check[a][b] = true;
  int next_a, next_b;
  for (int i = 0; i < 8; i++) {
    next_a = a + da[i];
    next_b = b + db[i];
    if (0 <= next_a && next_a < h && 0 <= next_b && next_b < w) {
      if (!check[next_a][next_b] && user[next_a][next_b]) {
        dfs(next_a, next_b);
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int in;
  while(1) {
    cin >> w >> h;
    if (!w && !h)
      return 0;

    memset(user, 0, sizeof(user));
    memset(check, false, sizeof(check));

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> in;
        user[i][j] = in;
      }
    }

    int result = 0;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (!check[i][j] && user[i][j]) {
          dfs(i, j);
          result++;
        }
      }
    }
    cout << result << "\n";
  }
}
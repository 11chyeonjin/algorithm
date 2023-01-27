#include <iostream>
using namespace std;

int R, C, K;
bool user[5][5] = { 0, };
bool visited[5][5] = { 0, };

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

int result = 0;

void dfs(int a, int b, int num) {
  // cout << a << " " << b << " " << num << "\n";
  if (a == R - 1 && b == C - 1) {
    // cout << "goal\n";
    if (num == K) 
      result++;
    return;
  }
  visited[a][b] = true;
  int next_a, next_b;
  for (int i = 0; i < 4; i++) {
    next_a = a + da[i];
    next_b = b + db[i];
    if (0 <= next_a && next_a < R && 0 <= next_b && next_b < C) {
      if (!user[next_a][next_b] && !visited[next_a][next_b]) {
        dfs(next_a, next_b, num + 1);
        visited[next_a][next_b] = false;
      }
    }
  }
}

int main() {
  cin >> R >> C >> K;
  string tmp;
  for (int i = R - 1; i >= 0; i--) {
    cin >> tmp;
    for (int j = 0; j < C; j++) {
      if (tmp[j] == 'T') {
        // cout << i << " " << j << " TT \n";
        user[i][j] = true;
      }
    }
  }

  dfs(0, 0, 1);

  cout << result;

  return 0;
}
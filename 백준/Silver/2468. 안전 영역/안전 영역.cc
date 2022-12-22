#include <cstring>
#include <iostream>
using namespace std;

int user[100][100] = {0};
bool visited[100][100] = {false};

int maxH = 0;
int minH = 101;

int result = 1;
int tmpResult = 0;

int N;

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

void dfs(int a, int b, int h) {
  visited[a][b] = true;
  int next_a, next_b;
  for (int i = 0; i < 4; i++) {
    next_a = a + da[i];
    next_b = b + db[i];
    if (next_a >= 0 && next_a < N && next_b >= 0 && next_b < N) {
      if (user[next_a][next_b] > h  && !visited[next_a][next_b]) {
          dfs(next_a, next_b, h);
      }
    }
  }
}

int main() {
  cin >> N;
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> tmp;
      maxH = max(maxH, tmp);
      minH = min(minH, tmp);
      user[i][j] = tmp;
    }
  }

  for (int h = minH; h <= maxH; h++) {
    tmpResult = 0;
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (user[i][j] > h && !visited[i][j]) {
          tmpResult++;
          dfs(i, j, h);
        }
      }
    }
    result = max(result, tmpResult);
  }

  cout << result;

  return 0;
}
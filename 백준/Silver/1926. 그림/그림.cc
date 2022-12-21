#include <iostream>
using namespace std;

int n, m;
bool user[500][500] = { false };
bool visited[500][500] = { false };
int total = 0; // 그림의 총 개수
int count = 0; // 그림 넓이 계산용
int maxCount = 0;

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

void dfs(int a, int b) {
  visited[a][b] = true;
  count++;
  int next_a, next_b;
  for (int i = 0; i < 4; i++) {
    next_a = a + da[i];
    next_b = b + db[i];
    if (next_a >= 0 && next_a < n && next_b >= 0 && next_b < m) {
      if (user[next_a][next_b] && !visited[next_a][next_b])
        dfs(next_a, next_b);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  int tmp;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> tmp;
      user[i][j] = tmp;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (user[i][j] && !visited[i][j]) {
        count = 0;
        dfs(i, j);
        total++;
        maxCount = max(maxCount, count);
      }
    }
  }

  cout << total << "\n" << maxCount;

  return 0;
}
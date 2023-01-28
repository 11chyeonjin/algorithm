#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int A, B;
bool user[50][50] = { 0, };
int visited[50][50] = { 0, };
vector<pair<int, int>> landList;

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

int bfs(int a, int b) {
  int result = -1;
  queue<pair<int,int>> q;
  q.push({a, b});
  visited[a][b] = 1;
  while (!q.empty()) {
    int now_a = q.front().first;
    int now_b = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next_a = now_a + da[i];
      int next_b = now_b + db[i];
      if (0 <= next_a && next_a < A && 0 <= next_b && next_b < B) {
        if (user[next_a][next_b] && !visited[next_a][next_b]) {
          q.push({next_a, next_b});
          visited[next_a][next_b] = visited[now_a][now_b] + 1;
          result = max(result, visited[next_a][next_b]);
        }
      }
    }
  }
  return result;
}

int main() {
  cin >> A >> B;

  string tmp;
  for (int i = 0; i < A; i++) {
    cin >> tmp;
    for (int j = 0; j < B; j++) {
      if (tmp[j] == 'L') {
        user[i][j] = 1;
        landList.push_back({i, j});
      }
    }
  }

  int result = -1;
  for (pair<int, int> land : landList) {
    memset(visited, 0, sizeof(visited));
    result = max(result, bfs(land.first, land.second));
  }

  cout << result - 1;

  return 0;
}
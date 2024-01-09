#include <iostream>
#include <queue>
using namespace std;

int n, m;
int startA, startB;
int _map[1000][1000];
int visited[1000][1000]; // 모든 값을 +1 처리
int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

void bfs() {
  queue<pair<int,int>> q;
  q.push({startA, startB});
  visited[startA][startB] = 1;

  int nowA, nowB;
  while(!q.empty()) {
    nowA = q.front().first;
    nowB = q.front().second;
    q.pop();

    int nextA, nextB;
    for (int i = 0; i < 4; i++) {
      nextA = nowA + da[i];
      nextB = nowB + db[i];
      if (0 <= nextA && nextA < n && 0 <= nextB && nextB < m) {
        if (!visited[nextA][nextB] && _map[nextA][nextB]) {
          q.push({nextA, nextB});
          visited[nextA][nextB] = visited[nowA][nowB] + 1;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  int value;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> value;
      if (value == 2) {
        startA = i;
        startB = j;
      }
      _map[i][j] = value;
    }
  }

  bfs();

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!_map[i][j]) {
        cout << 0 << " ";
      } else {
        if (!visited[i][j]) {
          cout << -1 << " ";
        } else {
          cout << visited[i][j] - 1 << " ";
        }
      }
    }
    cout << "\n";
  }
}
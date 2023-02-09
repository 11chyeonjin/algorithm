#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int N, L, R;
int user[50][50] = { 0, };
bool visited[50][50] = { 0, };

int da[4] = { 0, 0, -1, 1 };
int db[4] = { -1, 1, 0, 0 };

bool setBorder() {
  bool result = false;
  int next_i, next_j;
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int n = 0; n < 4; n++) {
        next_i = i + da[n];
        next_j = j + db[n];
        if (0 <= next_i && next_i < N && 0 <= next_j && next_j < N) {
          tmp = abs(user[i][j] - user[next_i][next_j]);
          if (L <= tmp && tmp <= R) {
            result = true;
          }
        }
      }
    }
  }
  return result;
}

void bfs(int a, int b) {
  int sumV = 0;
  queue<pair<int, int>> q;
  queue<pair<int, int>> rq;
  q.push({a, b});
  rq.push({a, b});
  sumV += user[a][b];
  visited[a][b] = true;
  while(!q.empty()) {
    int now_a = q.front().first;
    int now_b = q.front().second;
    q.pop();
    int next_a, next_b;
    for (int i = 0; i < 4; i++) {
      next_a = now_a + da[i];
      next_b = now_b + db[i];
      if (0 <= next_a && next_a < N && 0 <= next_b && next_b < N) {
        if (!visited[next_a][next_b]) {
          if (L <= abs(user[now_a][now_b] - user[next_a][next_b]) && abs(user[now_a][now_b] - user[next_a][next_b]) <= R) {
            sumV += user[next_a][next_b];
            q.push({next_a, next_b});
            rq.push({next_a, next_b});
            visited[next_a][next_b] = true;
          }
        }
      }
    }
  }
  sumV /= rq.size();
  while(!rq.empty()) {
    user[rq.front().first][rq.front().second] = sumV;
    rq.pop();
  }
}

int main() {
  cin >> N >> L >> R;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> user[i][j];
    }
  }

  int result = 0;
  while(true) {
    if (!setBorder()){
      break;
    }
    result++;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (!visited[i][j]) {
          bfs(i, j);
        }
      }
    }

    // for (int i = 0; i < N; i++) {
    //   for (int j = 0; j < N; j++) {
    //     cout << user[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
  }

  cout << result;
  return 0;
}
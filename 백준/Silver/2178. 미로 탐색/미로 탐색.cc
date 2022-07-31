#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;

int N, M;

int user[101][101] = { 0 };
bool check[101][101] = { 0 };
int how[101][101] = { 0 };

int da[4] = { 1, -1, 0, 0 };
int db[4] = { 0, 0, 1, -1 };

void bfs(int a, int b) {
  queue<pair <int, int>> q;
  q.push({a, b});
  check[a][b] = true;
  while(!q.empty()) {
    int now_a = q.front().first;
    int now_b = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next_a = now_a + da[i];
      int next_b = now_b + db[i];
      if (0 <= next_a && next_a < N && 0 <= next_b && next_b < M) {
        if (user[next_a][next_b] && !check[next_a][next_b]) {
          check[next_a][next_b] = true;
          how[next_a][next_b] = how[now_a][now_b] + 1;
          
          q.push({next_a, next_b});
        }
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  string in;
  for (int i = 0; i < N; i++) {
    cin >> in;
    for (int j = 0; j < M; j++) {
      user[i][j] = in[j] - '0';
    }
  }

  bfs(0, 0);

  cout << how[N-1][M-1] + 1;

  return 0;  
}
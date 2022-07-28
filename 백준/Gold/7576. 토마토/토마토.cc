#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int tomato[1001][1001];
int check[1001][1001];
queue<pair <int, int>> q;

void bfs() {
  while(!q.empty()) {
    int now_a = q.front().first;
    int now_b = q.front().second;
    q.pop();
    tomato[now_a][now_b] = 1;
    if (now_a > 0)
      if (!check[now_a-1][now_b] && !tomato[now_a-1][now_b]) {
        q.push({now_a - 1, now_b});
        check[now_a - 1][now_b] = check[now_a][now_b] + 1;
      }
    if (now_b > 0)
      if (!check[now_a][now_b-1] && !tomato[now_a][now_b-1]) {
        q.push({now_a, now_b - 1});
        check[now_a][now_b-1] = check[now_a][now_b] + 1;
      }
    if (!check[now_a][now_b+1] && !tomato[now_a][now_b+1]) {
      q.push({now_a, now_b + 1});
      check[now_a][now_b+1] = check[now_a][now_b] + 1;
    }
    if (!check[now_a+1][now_b] && !tomato[now_a+1][now_b]) {
      q.push({now_a + 1, now_b});
      check[now_a+1][now_b] = check[now_a][now_b] + 1;
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M, in;
  cin >> M >> N;

  memset(tomato, -1, sizeof(tomato));
  memset(check, 0, sizeof(check));  

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> in;
      tomato[i][j] = in;
      if (in == 1) {
        q.push({i, j});
        check[i][j] = 1;
      }
    }
  }

  bfs();
  
  int max = -1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (tomato[i][j] == 0) {
        cout << -1;
        return 0;
      }
      if (max < check[i][j])
        max = check[i][j];
    }
  }

  cout << max - 1;
  return 0;
}
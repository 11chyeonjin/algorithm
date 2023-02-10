#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;

int visited[500001][2] = { 0, };
int Klist[1001] = { 0, };

void bfs(int n) {
  queue<pair<int, int>> q;
  q.push({n, 0});
  visited[n][0] = 0; // 일단 0..
  while(!q.empty()) {
    int now_where = q.front().first;
    int now_time = q.front().second;
    q.pop();
    int next_where;
    int next_time = now_time + 1;
    next_where = now_where + 1;
    if (0 <= next_where && next_where <= 500000) {
      if (!visited[next_where][next_time % 2]) {
        q.push({next_where, next_time});
        visited[next_where][next_time % 2] =  next_time;
      }
    }
    next_where = now_where - 1;
    if (0 <= next_where && next_where <= 500000) {
      if (!visited[next_where][next_time % 2]) {
        q.push({next_where, next_time});
        visited[next_where][next_time % 2] =  next_time;
      }
    }
    next_where = now_where * 2;
    if (0 <= next_where && next_where <= 500000) {
      if (!visited[next_where][next_time % 2]) {
        q.push({next_where, next_time});
        visited[next_where][next_time % 2] =  next_time;
      }
    }
  }
}

int main() {
  cin >> N >> K;

  if (N == K) {
    cout << 0;
    return 0;
  }

  bfs(N);
  
  Klist[0] = K;
  for (int i = 1; i <= 1000; i++) {
    Klist[i] = Klist[i - 1] + i;
    if (Klist[i] > 500000)
      break;
    if (visited[Klist[i]][i % 2] && visited[Klist[i]][i % 2] <= i) {
      cout << i;
      return 0;
    }
  }

  cout << -1;
  return 0;
}
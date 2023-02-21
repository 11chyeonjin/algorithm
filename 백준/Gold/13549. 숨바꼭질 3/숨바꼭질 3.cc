#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int visited[100001];
queue<int> q;

void tpVisited(int a, int t) { // 방문하지 않은 정점 a와 텔포 정점에 대해서
  int tmp = a;  // 모두 방문처리(도달시간 확인)와 큐에 push를 진행함
  while(0 < tmp && tmp <= 100000) {
    if (visited[K] != -1)
      break;
    if (visited[tmp] == -1) {
      visited[tmp] = t;
      q.push(tmp);
    }
    tmp *= 2;
  }
}

void bfs() {
  q.push(N);
  visited[N] = 0;
  while(visited[K] == -1 && !q.empty()) {
    int now = q.front();
    q.pop();
    tpVisited(now, visited[now]);
    if (visited[K] != -1)
      break;
    
    int next;
    
    next = now + 1;
    if (0 <= next && next <= 100000) {
      if (visited[next] == -1) {
        q.push(next);
        visited[next] = visited[now] + 1;
      }
    }

    next = now - 1;
    if (0 <= next && next <= 100000) {
      if (visited[next] == -1) {
        q.push(next);
        visited[next] = visited[now] + 1;
      }
    }
  }
}

int main() {
  cin >> N >> K;

  fill(visited, visited + 100001, -1);

  bfs();

  cout << visited[K];

  return 0;
}
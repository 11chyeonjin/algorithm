#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// bfs 너비 우선 탐색을 진행 
int N, K;
int result, resultTime;

queue<pair<int, int>> q;
int visited[100001]; // [_] 최단시간
int _count[100001] = { 0, }; // [_] 최단시간 도달방법

void bfs() {
  q.push({N, 0});
  visited[N] = 0;
  _count[N]++;
  int nowR, nowT;
  while(!q.empty()) {
    nowR = q.front().first;
    nowT = q.front().second;
    q.pop();
    if (nowR == K) {
      resultTime = nowT;
      result = _count[K];
      return;
    }
    int nextR;
    nextR = nowR + 1;
    if (0 <= nextR && nextR <= 100000) {
      if (visited[nextR] == -1) {
        q.push({nextR, nowT + 1});
        visited[nextR] = nowT + 1;
        _count[nextR] += _count[nowR];
      }
      else if (visited[nextR] == nowT + 1) {
        _count[nextR] += _count[nowR];
      }
    }
    nextR = nowR - 1;
    if (0 <= nextR && nextR <= 100000) {
      if (visited[nextR] == -1) {
        q.push({nextR, nowT + 1});
        visited[nextR] = nowT + 1;
        _count[nextR] += _count[nowR];
      }
      else if (visited[nextR] == nowT + 1) {
        _count[nextR] += _count[nowR];
      }
    }
    nextR = nowR * 2;
    if (0 <= nextR && nextR <= 100000) {
      if (visited[nextR] == -1) {
        q.push({nextR, nowT + 1});
        visited[nextR] = nowT + 1;
        _count[nextR] += _count[nowR];
      }
      else if (visited[nextR] == nowT + 1) {
        _count[nextR] += _count[nowR];
      }
    }
  }
}

int main() {
  cin >> N >> K;
  
  fill(visited, visited + 100001, -1);

  bfs();

  cout << resultTime << "\n" << result;

  return 0;
}
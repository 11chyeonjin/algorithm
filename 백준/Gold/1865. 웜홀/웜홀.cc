#include <iostream>
#include <vector>
#define INF 9123456789123456789
using namespace std;

int TC;
int N, M, W;

bool bf(int start, vector<pair<pair<int, int>, int>>& v, vector<long long>& dist, vector<bool>& visited);

void solution() {
  /*
    1. 벨만 포드를 이용해서 사이클 찾기
      1.0. 벨만포드는 다익스트라와 다르게 거치는 노드 수(엣지)를 기준으로 반복해서 순회한다. depth(n-1)만큼 반복
      1.1. 사이클의 여부만을 판단해야 하므로, 모든 노드를 거치는 것이 매우 중요
  */

  // 입력 부분 시작
  cin >> N >> M >> W;
  
  vector<pair<pair<int, int>, int>> v;
  vector<long long> dist(N + 1, INF);
  vector<bool> visited(N + 1, false);

  int from, to, cost;
  for (int i = 0; i < M; i++) {
    cin >> from >> to >> cost;
    v.push_back({{from, to}, cost});
    v.push_back({{to, from}, cost});
  }
  for (int i = 0; i < W; i++) {
    cin >> from >> to >> cost;
    v.push_back({{from, to}, -cost}); // 웜홀은 단방향
  }
  // 입력 부분 종료

  for (int i = 1; i <= N; i++) {
    if (visited[i] == false) {
      if (bf(i, v, dist, visited) == true) {
        cout << "YES\n";
        return;
      }
    }
  }

  cout << "NO\n";
}

bool bf(int start, vector<pair<pair<int, int>, int>>& v, vector<long long>& dist, vector<bool>& visited) {
  dist[start] = 0;
  visited[start] = true;

  for (int l = 0; l < N - 1; l++) {
    for (int i = 0; i < v.size(); i++) {
      int from = v[i].first.first;
      int to = v[i].first.second;
      long long cur_cost = v[i].second;

      if (dist[from] != INF) {
        if (dist[to] > cur_cost + dist[from]) { // min 함수를 사용할 수 있지만, 음의 사이클 검증을 위해 if 문으로 구현
          dist[to] = cur_cost + dist[from];
          visited[to] = true;
        }
      }
    }
  }

  for (int i = 0; i < v.size(); i++) {
    int from = v[i].first.first;
    int to = v[i].first.second;
    long long cur_cost = v[i].second;

    if (dist[from] != INF) {
      if (dist[to] > cur_cost + dist[from]) { 
        // 음의 사이클이 존재한다면
        return true;
      }
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> TC;

  while(TC--) {
    solution();
  }

  return 0;
}
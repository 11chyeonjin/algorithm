#include <iostream>
#include <vector>
#include <algorithm>
#define INF 987654321
using namespace std;

long long dist[501];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  vector<pair<pair<int,int>, int>> v;

  int startV, targetV, cost;
  for (int i = 0; i < M; i++) {
    cin >> startV >> targetV >> cost;
    v.push_back({{startV, targetV}, cost}); // 단방향
  }

  fill(dist, dist + N + 1, INF);
  dist[1] = 0;

  for (int i = 1; i <= N - 1; i++) {
    for (int j = 0; j < v.size(); j++) {
      int from = v[j].first.first;
      int to = v[j].first.second;
      long long now_cost = v[j].second;

      if (dist[from] != INF) {
        if (dist[to] > dist[from] + now_cost) {
          dist[to] = dist[from] + now_cost; 
        }
      }
    }
  }

  for (int j = 0; j < v.size(); j++) {
    int from = v[j].first.first;
    int to = v[j].first.second;
    long long now_cost = v[j].second;

    if (dist[from] != INF) {
      if (dist[to] > dist[from] + now_cost) {
        cout << -1;
        return 0;
      }
    }
  }

  for (int i = 2; i <= N; i++) {
    if (dist[i] == INF)
      cout << -1 << "\n";
    else
      cout << dist[i] << "\n";
  }

  return 0;
}
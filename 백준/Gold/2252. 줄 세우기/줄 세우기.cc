#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<int> result;

void topological_sort(vector<int> v[], vector<int>& indegree, int start) {
  queue<int> q;
  
  q.push(start);

  int now;
  while(!q.empty()) {
    now = q.front();
    result.push_back(now);
    indegree[now] = -1;
    q.pop();

    for (int i = 0; i < v[now].size(); i++) {
      indegree[v[now][i]]--;
      if (indegree[v[now][i]] == 0) {
        q.push(v[now][i]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  vector<int> v[N + 1]; // 후행 노드 정보를 담은 인접 리스트
  vector<int> indegree(N + 1, 0); // 선행되어야 하는 노드의 수 (내차수)

  int s, e;
  for (int i = 0; i < M; i++) {
    cin >> s >> e;
    v[s].push_back(e);
    indegree[e]++;
  }

  for (int i = 1; i <= N; i++) {
    if (indegree[i] == 0) {
      topological_sort(v, indegree, i);
    }
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}
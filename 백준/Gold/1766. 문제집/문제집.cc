#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int> result;

struct comp 
{
    bool operator() (int i1, int i2) {
        return i1 > i2;
    }
};

priority_queue<int, vector<int>, comp> pq;

void topology_func(vector<int> v[], vector<int>& indegree) {
  int now;
  
  while(!pq.empty()) {
    now = pq.top();
    result.push_back(now);
    pq.pop();

    for (int i = 0; i < v[now].size(); i++) {
      indegree[v[now][i]]--;
      if (indegree[v[now][i]] == 0) {
        pq.push(v[now][i]);
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N >> M;

  vector<int> v[N + 1];
  vector<int> indegree(N + 1, 0);

  int from, to;
  for (int i = 0; i < M; i++) {
    cin >> from >> to;
    v[from].push_back(to);
    indegree[to]++;
  }

  for (int i = 1; i <= N; i++) {
    if (indegree[i] == 0)
      pq.push(i);
  }

  topology_func(v, indegree);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}
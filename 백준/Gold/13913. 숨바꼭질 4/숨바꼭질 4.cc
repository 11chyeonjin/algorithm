#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int N, K;
int visited[100001];
vector<int> result;
queue<int> q;

void bfs() {
  // where
  q.push(N);
  visited[N] = -2;

  int nowWhere;
  while(visited[K] == -1 && !q.empty()) {
    nowWhere = q.front();
    q.pop();

    if (visited[K] != -1)
      break;

    int nextWhere;
    
    nextWhere = nowWhere + 1;
    if (0 <= nextWhere && nextWhere <= 100000) {
      if (visited[nextWhere] == -1) {
        q.push(nextWhere);
        visited[nextWhere] = nowWhere;
      }
    }

    nextWhere = nowWhere - 1;
    if (0 <= nextWhere && nextWhere <= 100000) {
      if (visited[nextWhere] == -1) {
        q.push(nextWhere);
        visited[nextWhere] = nowWhere;
      }
    }

    nextWhere = nowWhere * 2;
    if (0 <= nextWhere && nextWhere <= 100000) {
      if (visited[nextWhere] == -1) {
        q.push(nextWhere);
        visited[nextWhere] = nowWhere;
      }
    }
    
  }
}

int main() {
  cin >> N >> K;

  fill(visited, visited + 100001, -1);

  bfs();
  
  result.push_back(K);
  while(true) {
    int tmp = visited[result.back()];
    if (tmp == -2)
      break;
    result.push_back(tmp);
  }
  
  cout << result.size() - 1 << "\n";
  for (int i = result.size() - 1; i >= 0; i--) {
    cout << result[i] << " ";
  }

  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> user[1001];
bool check[1001];

void dfs(int where) {
  check[where] = true;
  cout << where << " ";
  int next;
  for (int i = 0; i < user[where].size(); i++) {
    next = user[where][i];
    if (!check[next])
      dfs(next);
  }
}

void bfs(int where) {
  queue<int> q;
  q.push(where);
  check[where] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    cout << now << " ";
    for (int i = 0; i < user[now].size(); i++) {
      int next = user[now][i];
      if (!check[next]) {
        q.push(next);
        check[next] = true;
      }
    }
  }
}


int main() {
  int N, M, V;
  cin >> N >> M >> V;

  int a, b;
  while (M--) {
    cin >> a >> b;
    user[a].push_back(b);
    user[b].push_back(a);
  }

  
  for (int i = 1; i <= N; i++) {
    sort(user[i].begin(), user[i].end());
  }
  memset(check, false, sizeof(check));
  dfs(V);
  cout << "\n";
  memset(check, false, sizeof(check));
  bfs(V);

  return 0;
}
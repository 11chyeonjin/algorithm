#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[1001];
vector<bool> check(1001, false);

void dfs(int where) {
  check[where] = true;
  int next;
  for (int i = 0; i < vec[where].size(); i++) {
    next = vec[where][i];
    if (!check[next]) {
      dfs(next);
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  int u, v;
  while(m--) {
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  int result = 0;
  for (int i = 1; i <= n; i++) {
    if (!check[i]) {
      result++;
      dfs(i);
    }
  }

  cout << result;
  return 0;
}
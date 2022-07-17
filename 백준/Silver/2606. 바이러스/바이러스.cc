#include <iostream>
#include <vector>
using namespace std;

vector<int> vec[101];
vector<bool> check(101, false);

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

  int total;
  cin >> total;
  int j;
  cin >> j;
  int u, v;
  while(j--) {
    cin >> u >> v;
    vec[u].push_back(v);
    vec[v].push_back(u);
  }

  dfs(1);
  int result = 0;
  for (int i = 1; i < check.size(); i++) {
    if (check[i]) {
      result++;
    }
  }

  cout << --result;
  return 0;
}
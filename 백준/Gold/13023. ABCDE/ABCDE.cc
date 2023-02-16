#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N, M;
vector<int> user[2000];
bool visited[2000] = { 0, };
int result = 0;

void dfs(int a, int d) {
  if (d == 5) {
    result = 1;
    return;
  }
  for (int i = 0; i < user[a].size(); i++) {
    if (!visited[user[a][i]]) {
      visited[user[a][i]] = true;
      dfs(user[a][i], d + 1);
      visited[user[a][i]] = false;
    }
  }
}

int main() {
  cin >> N >> M;
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    user[a].push_back(b);
    user[b].push_back(a);
  }

  for (int i = 0; i < N; i++) {
    if (user[i].size()) {
      memset(visited, 0, sizeof(visited));
      visited[i] = true;
      dfs(i, 1);
    }
    if (result)
      break;
  }

  cout << result;

  return 0;
}
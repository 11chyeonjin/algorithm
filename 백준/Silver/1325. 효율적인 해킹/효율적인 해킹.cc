#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;

vector<int> com[10001];
bool visited[10001] = { 0, };
vector<int> result(1, 0);

int dfs(int computer) {
  visited[computer] = true;
  int tmp = 1;
  if (!com[computer].size())
    return tmp;
  for (int i = 0; i < com[computer].size(); i++) {
    if (!visited[com[computer][i]])
      tmp += dfs(com[computer][i]);
  }
  return tmp;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> M;

  int a, b;
  while(M--) {
    cin >> a >> b;
    com[b].push_back(a);
  }
  
  int max_value = -1;
  for (int i = 1; i <= N; i++) {
    memset(visited, 0, sizeof(visited));
    result.push_back(dfs(i));
    max_value = max(max_value, result[i]);
  }

  for (int i = 1; i <= N; i++) {
    if (result[i] == max_value) {
      cout << i << " ";
    }
  }

  return 0;
}
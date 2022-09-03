#include <iostream>
using namespace std;

int N, M;

int visited[9];
int user[9];

void dfs(int count, int now)
{
  if (count == M) {
    for (int i = 0; i < M; i++) {
      cout << user[i] << " ";
    }
    cout << "\n";
  }
  else {
    for (int i = now; i <= N; i++) {
      user[count] = i;
      dfs(count + 1, i);
    }
  }
}

int main() {
  cin >> N >> M;

  dfs(0, 1);
  return 0;
}
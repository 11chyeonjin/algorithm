#include <iostream>
#include <cstring>
using namespace std;

int graph[51][51] = {0};
int check[51][51] = {0};

void dfs(int x, int y) {
  check[x][y] = 1;
  if (x < 50)
    if ((!check[x+1][y]) && graph[x+1][y])
      dfs(x+1, y);
  if (y < 50)
    if ((!check[x][y+1]) && graph[x][y+1])
      dfs(x, y+1);
  if (x > 0)
    if ((!check[x-1][y]) && graph[x-1][y])
      dfs(x-1, y);
  if (y > 0)
    if ((!check[x][y-1]) && graph[x][y-1])
      dfs(x, y-1);
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  int M, N, K;
  int x, y;
  int result;

  while(T--) {
    cin >> M >> N >> K;
    result = 0;
    while(K--) {
      cin >> x >> y;
      graph[x][y] = 1;
    }
    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if ((!check[i][j]) && graph[i][j]) {
          dfs(i, j);
          result++;
        }
      }
    }
    cout << result << "\n";
    memset(check, 0, sizeof(check));
    memset(graph, 0, sizeof(graph));
  }

  return 0;
}
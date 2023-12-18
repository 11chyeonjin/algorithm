#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

int bus[101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;

  fill(&bus[0][0], &bus[100][101], INF);
  int from, to, cost;
  for (int i = 0; i < m; i++) {
    cin >> from >> to >> cost;
    bus[from][to] = min(cost, bus[from][to]);
  }
  for (int i = 1; i <= n; i++) {
    bus[i][i] = 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (bus[i][k] != INF && bus[k][j] != INF) {
          bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (bus[i][j] != INF)
        cout << bus[i][j] << " ";
      else
        cout << 0 << " ";
    }
    cout << "\n";
  }

  return 0;
}
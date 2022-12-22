#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool user[100][100] = { false };
bool visited[100][100] = { false };

int M, N, K;

vector<int> result;

int resultTotal = 0;
int count_v = 0;

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

void dfs(int a, int b) {
  visited[a][b] = true;
  count_v++;
  int next_a, next_b;
  for (int i = 0; i < 4; i++) {
    next_a = a + da[i];
    next_b = b + db[i];
    if (next_a >= 0 && next_a < N && next_b >= 0 && next_b < M) {
      if (!user[next_a][next_b] && !visited[next_a][next_b]) {
        dfs(next_a, next_b);
      }
    }
  }
}

int main() {
  cin >> M >> N >> K;

  int a, b, aa, bb;
  for (int i = 0; i < K; i++) {
    cin >> a >> b >> aa >> bb;
    for (int p = a; p < aa; p++) {
      for (int q = b; q < bb; q++) {
        user[p][q] = true;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!user[i][j] && !visited[i][j]) {
        resultTotal++;
        count_v = 0;
        dfs(i, j);
        result.push_back(count_v);
      }
    }
  }

  sort(result.begin(), result.end());

  cout << resultTotal << "\n";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int A, B;
bool cheese[100][100] = { 0, };
bool visited[100][100] = { 0, };

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

int meltedCheese = 0;

vector<int> result;

void dfs(int a, int b) {
  visited[a][b] = true;
  int next_a, next_b;
  for (int i = 0; i < 4; i++) {
    next_a = a + da[i];
    next_b = b + db[i];
    if (next_a >= 0 && next_a < A && next_b >= 0 && next_b < B) {
      if (!visited[next_a][next_b]) {
        if (!cheese[next_a][next_b]) {
          dfs(next_a, next_b);
        }
        else {
          visited[next_a][next_b] = true;
          cheese[next_a][next_b] = false;
          meltedCheese++;
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> A >> B;
  int tmp;
  for (int i = 0; i < A; i++) {
    for (int j = 0; j < B; j++) {
      cin >> tmp;
      cheese[i][j] = tmp;
    }
  }

  while(true) {
    memset(visited, 0, sizeof(visited));
    meltedCheese = 0;
    dfs(0, 0);
    if (!meltedCheese) {
      break;
    }
    else {
      result.push_back(meltedCheese);
    }
  }
  
  cout << result.size() << "\n" << result[result.size() - 1];

  return 0;
}
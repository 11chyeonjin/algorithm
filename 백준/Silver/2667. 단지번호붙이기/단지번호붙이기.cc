#include <iostream>
#include <queue>
using namespace std;

int user[25][25];
bool check[25][25] = { false };

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

int N;

int bfs(int a, int b) {
  queue<pair <int, int>> q;
  q.push({a, b});
  check[a][b] = true;
  int how_many = 1;
  while(!q.empty()) {
    int now_a = q.front().first;
    int now_b = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next_a = now_a + da[i];
      int next_b = now_b + db[i];
      if (0 <= next_a && next_a < N && 0 <= next_b && next_b < N) {
        if (!check[next_a][next_b] && user[next_a][next_b]) {
          q.push({next_a, next_b});
          check[next_a][next_b] = true;
          how_many++;
        }
      }
    }
  }
  return how_many;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  priority_queue<int, vector<int>, greater<int>> result;
  
  cin >> N;
  string in;
  for (int i = 0; i < N; i++) {
    cin >> in;
    for (int j = 0; j < N; j++) {
      user[i][j] = in[j] - '0';
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (user[i][j] && !check[i][j]) {
        result.push(bfs(i, j));
      }
    }
  }

  cout << result.size() << "\n";
  while(!result.empty()) {
    cout << result.top() << "\n";
    result.pop();
  }

  return 0;
}
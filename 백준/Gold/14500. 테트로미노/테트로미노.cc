#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;

int N, M;

int result = 0;

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

int user[500][500];
bool check[500][500] = { false };

void dfs(int a, int b, int depth, int sum) {
  if (depth == 4) {
    result = max(result, sum);
    return;
  }
  
  for (int i = 0; i < 4; i++) {
    int next_a = a + da[i];
    int next_b = b + db[i];
    if (0 <= next_a && next_a < N && 0 <= next_b && next_b < M) {
      if (!check[next_a][next_b]) {
        check[next_a][next_b] = true;
        dfs(next_a, next_b, depth + 1, sum + user[next_a][next_b]);
        check[next_a][next_b] = false;
      }
    }
  }
}

void T(int a, int b) {
  int no = 0; // 십자가 모양으로 하였을 때, 가능하지 않은 칸의 개수
  int sum = user[a][b];
  for (int i = 0; i < 4; i++) {
    int next_a = a + da[i];
    int next_b = b + db[i];
    if (0 <= next_a && next_a < N && 0 <= next_b && next_b < M) {
      sum += user[next_a][next_b];
    }
    else {
      no++;
    }
  }

  if (no == 2) {
    return;
  }
  else if (no == 1) {
    result = max(result, sum);
  }
  else {
    for (int i = 0; i < 4; i++) {
      int next_a = a + da[i];
      int next_b = b + db[i];
      result = max(result, sum - user[next_a][next_b]);
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int in;

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> in;
      user[i][j] = in;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      check[i][j] = true;
      dfs(i, j, 1, user[i][j]);
      T(i, j);      
      check[i][j] = false;
    }
  }

  cout << result;

  return 0;
}
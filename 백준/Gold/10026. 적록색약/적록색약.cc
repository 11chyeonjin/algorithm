#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int N;

int user[100][100];
bool check[100][100] = { false };

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

void bfs_normal(int a, int b, int color) {
  queue<pair<int, int>> q;
  q.push({a, b});
  check[a][b] = true;
  while(!q.empty()) {
    int now_a = q.front().first;
    int now_b = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next_a = now_a + da[i];
      int next_b = now_b + db[i];
      if (0 <= next_a && next_a < N && 0 <= next_b && next_b < N) {
        if (!check[next_a][next_b] && user[next_a][next_b] == color) {
          q.push({next_a, next_b});
          check[next_a][next_b] = true;
        }
      }
    }
  }
}

void bfs_rg(int a, int b) {
  queue<pair<int, int>> q;
  q.push({a, b});
  check[a][b] = true;
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
        }
      }
    }
  }
}

void bfs_b(int a, int b) {
  queue<pair<int, int>> q;
  q.push({a, b});
  check[a][b] = true;
  while(!q.empty()) {
    int now_a = q.front().first;
    int now_b = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next_a = now_a + da[i];
      int next_b = now_b + db[i];
      if (0 <= next_a && next_a < N && 0 <= next_b && next_b < N) {
        if (!check[next_a][next_b] && !user[next_a][next_b]) {
          q.push({next_a, next_b});
          check[next_a][next_b] = true;
        }
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  cin >> N;
  string in;

  for (int i = 0; i < N; i++) {
    cin >> in;
    for (int j = 0; j < N; j++) {
      if (in[j] == 'R')
        user[i][j] = 1;
      else if (in[j] == 'G')
        user[i][j] = 2;
      else  // B 일때
        user[i][j] = 0;
    }
  }

  int normal_result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!check[i][j]) {
        bfs_normal(i, j, user[i][j]);
        normal_result++;
      }
    }
  }

  memset(check, false, sizeof(check));
  
  int a_result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!check[i][j] && user[i][j]) {
        bfs_rg(i, j);
        a_result++;
      }
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!check[i][j] && !user[i][j]) {
        bfs_b(i, j);
        a_result++;
      }
    }
  }
  
  cout << normal_result << " " << a_result;
  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;

vector< vector<int> > originv(8, vector<int> (8));
vector< vector<int> > copyv(8, vector<int> (8));

queue <pair<int, int>> originq;
queue <pair<int, int>> copyq;

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

void virus() { // 바이러스 전파 함수
  copyq = originq;
  while(!copyq.empty()) {
    int now_a = copyq.front().first;
    int now_b = copyq.front().second;
    copyv[now_a][now_b] = 2;
    copyq.pop();
    for (int i = 0 ; i < 4 ; i++) {
      int next_a = now_a + da[i];
      int next_b = now_b + db[i];
      if (0 <= next_a && next_a < N && 0 <= next_b && next_b < M) {
        if (!copyv[next_a][next_b]) {
          copyq.push({next_a, next_b});
        }
      }
    }
  }
}

int safe_dfs() {
  int result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!copyv[i][j])
        result++;
    }
  }
  return result;
}

vector<pair<int, int>> where_zero;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int in;
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> in;
      originv[i][j] = in;
      if (in == 2)
        originq.push({i, j}); // 방문 처리 없이 진행
      else if (!in)
        where_zero.push_back({i, j});
    }
  }
  
  int size = where_zero.size();
  int max = -1;
  for (int i = 0; i < size - 2; i++) {
    for (int j = i + 1; j < size - 1; j++) {
      for (int k = j + 1; k < size; k++) {
        copyv = originv;
        copyv[where_zero[i].first][where_zero[i].second] = 1;
        copyv[where_zero[j].first][where_zero[j].second] = 1;
        copyv[where_zero[k].first][where_zero[k].second] = 1;
        virus();
        int result = safe_dfs();
        if (result > max) {
          max = result;
        }
      }
    }
  }

  cout << max;
  return 0;
}
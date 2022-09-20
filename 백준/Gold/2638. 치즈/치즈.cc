#include <iostream>
#include <tuple>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, M;

int second = 0;

queue<pair<int, int>> q;
vector<tuple<int, int, int>> cheese; // x, y, air_count

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

bool user[100][100]; // 치즈의 위치 저장
bool visited[100][100];

int cheese_air_count[100][100] = { 0 };

void air_dfs() {
  while(!q.empty()) {
    int now_a = q.front().first;
    int now_b = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int next_a = now_a + da[i];
      int next_b = now_b + db[i];
      if (0 <= next_a && next_a < N && 0 <= next_b && next_b < M) {
        if (!visited[next_a][next_b]) {
          if (!user[next_a][next_b]) { // 다음 칸이 공기라면,
            q.push({next_a, next_b});
            visited[next_a][next_b] = true;
          }
          else {
            cheese_air_count[next_a][next_b]++;
          }
        }
      }
    } 
  }
}

void cheese_remove() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (cheese_air_count[i][j] >= 2) {
        cheese_air_count[i][j] = 0;
        user[i][j] = 0;
        q.push({i, j});
        visited[i][j] = true;
      }
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
  
  q.push({0, 0});
  q.push({N - 1, M - 1});
  q.push({0, M - 1});
  q.push({N - 1, 0});
  visited[0][0] = true;
  visited[N - 1][M - 1] = true;
  visited[0][M - 1] = true;
  visited[N - 1][0] = true;

  while(!q.empty()) {
    air_dfs();

    // cout << "===============\n";
    // for (int i = 0; i < N; i++) {
    //   for (int j = 0; j < M; j++) {
    //     cout << cheese_air_count[i][j] << " ";
    //   }
    //   cout << "\n";
    // }
    // cout << "===============\n";
    
    cheese_remove();
    second++;
  }
  
  cout << second - 1;
  
  return 0;
}
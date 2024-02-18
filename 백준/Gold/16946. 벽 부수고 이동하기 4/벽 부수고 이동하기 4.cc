#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int _map[1000][1000];
bool visited[1000][1000];

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

void bfs(int start_a, int start_b,  vector<vector<pair<int, int>>>& map_count, int bfs_index) {
  queue<pair<int,int>> q;
  vector<pair<int,int>> v;
  
  q.push({start_a, start_b});
  v.push_back({start_a, start_b});
  visited[start_a][start_b] = true;

  int now_a, now_b;
  while(!q.empty()) {
    now_a = q.front().first;
    now_b = q.front().second;
    q.pop();

    int next_a, next_b;
    for (int i = 0; i < 4; i++) {
      next_a = now_a + da[i];
      next_b = now_b + db[i];

      if (0 <= next_a && next_a < N && 0 <= next_b && next_b < M) {
        if (_map[next_a][next_b] == 0) {
          if (!visited[next_a][next_b]) {
            q.push({next_a, next_b});
            v.push_back({next_a, next_b});
            visited[next_a][next_b] = true;
          }
        }
      }
    }
  }

  for (int i = 0; i < v.size(); i++) {
    map_count[v[i].first][v[i].second] = {v.size(), bfs_index};
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  /* 
    1. 단순하게 벽을 기준으로 하는 반복 BFS로 접근
      : 1000 * 1000 * 1000 * 1000 로 불가능

    2. 빈 공간마다의 면적을 모두 파악하고, 벽 상하좌우 빈공간의 면적을 더하는 방식으로 계산
  */
  cin >> N >> M;

  fill(&visited[0][0], &visited[N - 1][M], false);

  vector<vector<pair<int, int>>> map_count(N, vector<pair<int, int>>(M, {0, 0}));

  string str_in;
  for (int i = 0; i < N; i++) {
    cin >> str_in;
    for (int j = 0; j < M; j++) {
      _map[i][j] = str_in[j] - '0';
    }
  }

  int bfs_index = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (!_map[i][j] && !visited[i][j]) {
        bfs(i, j, map_count, bfs_index++);
      }
    }
  }

  vector<vector<int>> result(N, vector<int>(M, 0)); // {value, bfs_index}

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (_map[i][j]) {

        int _sum = 1;
        int next_a, next_b;
        vector<int> index_check;
        for (int k = 0; k < 4; k++) {
          next_a = i + da[k];
          next_b = j + db[k];

          bool check_bool = false;

          if (0 <= next_a && next_a < N && 0 <= next_b && next_b < M) {
            
            for (int l = 0; l < index_check.size(); l++) {
              if (map_count[next_a][next_b].second == index_check[l])
                check_bool = true;
            }
            
            if (!check_bool) {
              _sum = (_sum + map_count[next_a][next_b].first % 10) % 10;
              index_check.push_back(map_count[next_a][next_b].second);
            }
          }
        }

        result[i][j] = _sum;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cout << result[i][j];
    }
    cout << "\n";
  }


  return 0;
}
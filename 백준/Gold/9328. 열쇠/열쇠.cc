#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int T, h, w;
int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

int bfs(vector<vector<char>>& v, vector<bool>& keys) {
  vector<vector<bool>> visited(h + 2, vector<bool>(w + 2, false));
  queue<pair<int,int>> q;
  vector<pair<int,int>> closed_doors;

  int rst = 0;
  
  q.push({0, 0});
  visited[0][0] = true;

  while(!q.empty()) {
    int now_a = q.front().first;
    int now_b = q.front().second;
    q.pop();
    
    if (v[now_a][now_b] == '$') {
      rst++;
    }

    for (int i = 0; i < 4; i++) {
      int next_a = now_a + da[i];
      int next_b = now_b + db[i];

      if (0 <= next_a && next_a < h + 2 && 0 <= next_b && next_b < w + 2) {
        if (!visited[next_a][next_b] && v[next_a][next_b] != '*') {
          if (v[next_a][next_b] == '.') {
            q.push({next_a, next_b});
            visited[next_a][next_b] = true;
          } else if ('a' <= v[next_a][next_b] && v[next_a][next_b] <= 'z') {
            keys[v[next_a][next_b] - 'a'] = true;
            q.push({next_a, next_b});
            visited[next_a][next_b] = true;
          } else if ('A' <= v[next_a][next_b] && v[next_a][next_b] <= 'Z') {
            if (keys[v[next_a][next_b] - 'A']) {
              // 해당 문에 대한 키가 있다면,
              q.push({next_a, next_b});
              visited[next_a][next_b] = true;
            } else {
              // 키가 현재 없다면, 닫힌 문 vector에 추가
              closed_doors.push_back({next_a, next_b});
            }
          } else {
            q.push({next_a, next_b});
            visited[next_a][next_b] = true;
          }
        }
      }
    }
  }

  while(!closed_doors.empty()) {
    int idx = 0;
    while(idx < closed_doors.size()) {
      if (keys[v[closed_doors[idx].first][closed_doors[idx].second] - 'A']) {
        q.push({closed_doors[idx].first, closed_doors[idx].second});
        visited[closed_doors[idx].first][closed_doors[idx].second] = true;
        closed_doors.erase(closed_doors.begin() + idx);
      } else {
        idx++;
      }
    }

    if (q.empty())
      break;

    while(!q.empty()) {
      int now_a = q.front().first;
      int now_b = q.front().second;
      q.pop();
  
      if (v[now_a][now_b] == '$') {
        rst++;
      }
  
      for (int i = 0; i < 4; i++) {
        int next_a = now_a + da[i];
        int next_b = now_b + db[i];
  
        if (0 <= next_a && next_a < h + 2 && 0 <= next_b && next_b < w + 2) {
          if (!visited[next_a][next_b] && v[next_a][next_b] != '*') {
            if (v[next_a][next_b] == '.') {
              q.push({next_a, next_b});
              visited[next_a][next_b] = true;
            } else if ('a' <= v[next_a][next_b] && v[next_a][next_b] <= 'z') {
              keys[v[next_a][next_b] - 'a'] = true;
              q.push({next_a, next_b});
              visited[next_a][next_b] = true;
            } else if ('A' <= v[next_a][next_b] && v[next_a][next_b] <= 'Z') {
              if (keys[v[next_a][next_b] - 'A']) {
                // 해당 문에 대한 키가 있다면,
                q.push({next_a, next_b});
                visited[next_a][next_b] = true;
              } else {
                // 키가 현재 없다면, 닫힌 문 vector에 추가
                closed_doors.push_back({next_a, next_b});
              }
            } else {
              q.push({next_a, next_b});
              visited[next_a][next_b] = true;
            }
          }
        }
      }
    }
  }
  
  return rst;
}

void main_func() {
  cin >> h >> w;

  vector<vector<char>> v(h + 2, vector<char>(w + 2, '.')); // 0 ~ h + 1, 0 ~ w + 1
  vector<bool> keys(26, false); // map처럼 열쇠 보유 여부를 저장
  
  string str_in;
  for (int i = 0; i < h; i++) {
    cin >> str_in;
    for (int j = 0; j < w; j++) {
      v[i + 1][j + 1] = str_in[j];
    }
  }

  cin >> str_in;
  for (int i = 0; i < str_in.size(); i++) {
    if (str_in[i] == '0')
      break;

    keys[str_in[i] - 'a'] = true;
  }

  cout << bfs(v, keys) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  /*
    1. queue를 이용한 bfs
    1.1. 건물의 외부 상하좌우에 한 줄 씩 이동 가능한 빈 공간을 추가해야한다.
    1.2. 열쇠는 재사용이 가능함.
    1.3. bfs 진행 중에는 도달한 문을 따로 저장할 수 있어야 하는지?
    1.4. 닫힌 문에 대해서 더 생각해 봐야함 -> 무한루프 발생 가능
  */

  cin >> T;
  while(T--) {
    main_func();
  }

  return 0;
}
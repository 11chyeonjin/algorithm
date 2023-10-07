#include <iostream>
#include <queue>
using namespace std;

int user[5][5] = { 0, };
int visited[5][5] = { 0, };
int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };
int r, c;
int max = 100;

int bfs() {
  queue<pair<int,int>> q;
  q.push({r,c});
  visited[r][c] = 1; // 학생의 첫 위치가 +1
  int now_a, now_b;
  
  while(!q.empty()) {
    now_a = q.front().first;
    now_b = q.front().second;
    q.pop();
    int next_a, next_b;
    
    for (int i = 0; i < 4; i++) {
      
      next_a = now_a + da[i];
      next_b = now_b + db[i];
      
      if (0 <= next_a && next_a < 5 && 0 <= next_b && next_b < 5) {
        if (!visited[next_a][next_b]) {
          if (!user[next_a][next_b]) {
            q.push({next_a, next_b});
            visited[next_a][next_b] = visited[now_a][now_b] + 1;
          }
          else if (user[next_a][next_b] == 1) {
            return visited[now_a][now_b] + 1;
          }
        }
      }
    }
  }
  return 0;
}

int main() {
  cin.tie(NULL);
  cout.tie(NULL);
  
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> user[i][j];
    }
  }
  
  cin >> r >> c;

  int result = bfs() - 1;

  cout << result;
  
  return 0;
}
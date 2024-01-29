#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int R, C;
int _map[20][20];
int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };
int maxResult = 1;

void dfs(int nowA, int nowB, vector<bool>& alpha, vector<vector<bool>>& visited, int num) {
  // # size 함수의 return값은 unsigned int임

  int nextA, nextB;
  for (int i = 0; i < 4; i++) {
    nextA = nowA + da[i];
    nextB = nowB + db[i];
    if (0 <= nextA && nextA < R && 0 <= nextB && nextB < C) {
      if (!visited[nextA][nextB]) {
        if (!alpha[_map[nextA][nextB]]) {
          
          alpha[_map[nextA][nextB]] = true;
          visited[nextA][nextB] = true;
          maxResult = max(maxResult, ++num);
          
          dfs(nextA, nextB, alpha, visited, num);
          
          alpha[_map[nextA][nextB]] = false;
          visited[nextA][nextB] = false;
          num--;
          
        }
      }
    }
  }
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // 지나온 경로에 관련된 문제 => DFS, 백트래킹
  cin >> R >> C;

  string str_in;
  for (int i = 0; i < R; i++) {
    cin >> str_in;
    for (int j = 0; j < C; j++) {
      _map[i][j] = str_in[j] - 'A';
    }
  }

  vector<bool> alpha(26, false);
  vector<vector<bool>> visited(20, vector<bool> (20, false));

  alpha[_map[0][0]] = true;
  visited[0][0] = true;
  dfs(0, 0, alpha, visited, 1);

  cout << maxResult;

  return 0;
}
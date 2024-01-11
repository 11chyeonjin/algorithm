#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
int m[600][600];
bool visited[600][600];
int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };
int startA, startB;

int bfs() {
  int result = 0;
  queue<pair<int,int>> q;
  q.push({startA, startB});
  visited[startA][startB] = true;

  int nowA, nowB;
  while(!q.empty()) {
    nowA = q.front().first;
    nowB = q.front().second;
    q.pop();

    int nextA, nextB;
    for (int i = 0; i < 4; i++) {
      nextA = nowA + da[i];
      nextB = nowB + db[i];
      if (0 <= nextA && nextA < N && 0 <= nextB && nextB < M) {
        if (!visited[nextA][nextB] && m[nextA][nextB]) {
          q.push({nextA, nextB});
          visited[nextA][nextB] = true;
          if (m[nextA][nextB] == 2) {
            result++;
          }
        }
      }
    }
  }

  return result;
}

int main() {
  cin >> N >> M;
  string tmp;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    for (int j = 0; j < M; j++) {
      if (tmp[j] == 'O') {
        m[i][j] = 1;
      } else if (tmp[j] == 'P') {
        m[i][j] = 2;
      } else if (tmp[j] == 'X') {
        m[i][j] = 0;
      } else if (tmp[j] == 'I') {
        m[i][j] = 3;
        startA = i;
        startB = j;
      }
    }
  }

  fill(&visited[0][0], &visited[N - 1][M], false);

  int result = bfs();
  if (result == 0) {
    cout << "TT";
  } else
    cout << result;

  return 0;
}
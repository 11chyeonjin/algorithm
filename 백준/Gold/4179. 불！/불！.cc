#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int R, C;

int user[1000][1000] = { 0, };
bool visited[1000][1000] = { 0, };

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

queue<tuple<int, int, int>> fire;
queue<tuple<int, int, int>> human;

int bfs() {
  while(!human.empty()) {
    int nowHa = get<0>(human.front());
    int nowHb = get<1>(human.front());
    int nowTime = get<2>(human.front());

    while(!fire.empty()) {
      int nowFa = get<0>(fire.front());
      int nowFb = get<1>(fire.front());
      int nowFtime = get<2>(fire.front());
      if (nowTime != nowFtime)
        break;
      fire.pop();
      int nextFa, nextFb;
      for (int i = 0; i < 4; i++) {
        nextFa = nowFa + da[i];
        nextFb = nowFb + db[i];
        if (0 <= nextFa && nextFa < R && 0 <= nextFb && nextFb < C) {
          if (!user[nextFa][nextFb]) {
            fire.push({nextFa, nextFb, nowFtime + 1});
            user[nextFa][nextFb] = 2;
          }
        }
      }
    }
    
    human.pop();
    int nextHa, nextHb;
    for (int i = 0; i < 4; i++) {
      nextHa = nowHa + da[i];
      nextHb = nowHb + db[i];
      if (0 <= nextHa && nextHa < R && 0 <= nextHb && nextHb < C) {
        if (!user[nextHa][nextHb] && !visited[nextHa][nextHb]) {
          human.push({nextHa, nextHb, nowTime + 1});
          visited[nextHa][nextHb] = true;
        }
      }
      else { // 가장자리라면,
        return nowTime + 1;
      }
    }
  }
  return -1;
}

int main() {
  cin >> R >> C;
  string tmp;
  int a, b;
  for (int i = 0; i < R; i++) {
    cin >> tmp;
    for (int j = 0; j < C; j++) {
      if (tmp[j] == '#') {
        user[i][j] = 1;
      }
      else {
        if (tmp[j] == 'F') {
          user[i][j] = 2;
          fire.push({i, j, 0});
        }
        else {
          user[i][j] = 0;
          if (tmp[j] == 'J') {
            human.push({i, j, 0});
          }
        }
      }
    }
  }

  int result = bfs();
  if (result == -1)
    cout << "IMPOSSIBLE";
  else
    cout << result;

  return 0;
}
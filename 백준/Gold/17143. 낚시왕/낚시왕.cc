#include <iostream>
#include <vector>
using namespace std;

int R, C, M;
int dy[5] = {0, -1, 1, 0, 0}; // 원, 상, 하, 우, 좌
int dx[5] = {0, 0, 0, 1, -1};

int main() {
  cin >> R >> C >> M;

  vector<vector<int>> v(R + 1, vector<int>(C + 1, -1)); // 상어가 없는 칸은 -1로 초기화
  vector<pair<int,int>> shark; // {속력, 크기}
  vector<int> sharkDir; // 이동방향

  vector<int> caughtShark;
  
  // 입력 구현 부분
  int r, c, s, d, z;
  // (r,c):상어의위치  s:속력  d:이동방향  z:크기
  for (int i = 0; i < M; i++) {
    cin >> r >> c >> s >> d >> z;
    
    v[r][c] = i;
    shark.push_back({s, z});
    sharkDir.push_back(d);
  }

  for (int i = 1; i <= C; i++) {
    // 상어 잡이
    for (int j = 1; j <= R; j++) {
      if (v[j][i] != -1) {
        caughtShark.push_back(v[j][i]);
        v[j][i] = -1;
        break;
      }
    }

    // 상어 이동
    vector<pair<int,pair<int,int>>> movingShark; // {번호, {새y위치,새x위치}}
    for (int y = 1; y <= R; y++) {
      for (int x = 1; x <= C; x++) {
        if (v[y][x] != -1) {
          int curShark = v[y][x];
          int curSharkSpeed = shark[curShark].first;
          int curSharkDir = sharkDir[curShark];
          int curY = y, curX = x;

          // 상어 이동
          if (curSharkDir == 1 || curSharkDir == 2) { // 상하 이동
            curSharkSpeed %= (2 * (R - 1));
            while (curSharkSpeed--) {
              if (curY == 1) curSharkDir = 2;
              else if (curY == R) curSharkDir = 1;
              curY += dy[curSharkDir];
            }
          } else { // 좌우 이동
            curSharkSpeed %= (2 * (C - 1));
            while (curSharkSpeed--) {
              if (curX == 1) curSharkDir = 3;
              else if (curX == C) curSharkDir = 4;
              curX += dx[curSharkDir];
            }
          }

          sharkDir[curShark] = curSharkDir;
          movingShark.push_back({curShark, {curY, curX}});
          v[y][x] = -1;
        }
      }
    }

    // 상어 배치
    for (int j = 0; j < movingShark.size(); j++) {
      int curSharkY = movingShark[j].second.first;
      int curSharkX = movingShark[j].second.second;
      int curSharkNum = movingShark[j].first;
      if (v[curSharkY][curSharkX] == -1) {
        v[curSharkY][curSharkX] = curSharkNum;
      } else {
        if (shark[v[curSharkY][curSharkX]].second < shark[curSharkNum].second) {
          v[curSharkY][curSharkX] = curSharkNum;
        }
      }
    }
  }

  int rst = 0;
  for (int i = 0; i < caughtShark.size(); i++) {
    rst += shark[caughtShark[i]].second;
  }

  cout << rst;

  return 0;
}
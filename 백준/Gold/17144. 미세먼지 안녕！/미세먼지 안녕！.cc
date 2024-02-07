#include <iostream>
#include <vector>
using namespace std;

int R, C, T;
int room[50][50];
vector<int> ac; // 공기청정기의 b 좌표 윗부분이 0, 아랫부분이 1로 저장

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 }; 

// 윗 공기청정기 // 북, 동, 남, 서 방향으로 이동
int ac0_da[4] = { -1, 0, 1, 0 }; 
int ac0_db[4] = { 0, 1, 0, -1 }; 

// 아랫 공기청정기 // 남, 동, 북, 서 방향으로 이동
int ac1_da[4] = { 1, 0, -1, 0 };
int ac1_db[4] = { 0, 1, 0, -1 };


void diff() {
  vector<pair<pair<int,int>, int>> change; // { { a, b } , 변화량 }

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (room[i][j] > 0) {
        int next_a, next_b;
        int diff_count = 0;
        for (int k = 0; k < 4; k++) {
          next_a = i + da[k];
          next_b = j + db[k];
          if (0 <= next_a && next_a < R && 0 <= next_b && next_b < C) {
            if (room[next_a][next_b] != -1) {
              change.push_back({{next_a, next_b}, room[i][j] / 5});
              diff_count++;
            }
          }
        }
        change.push_back({{i, j}, - room[i][j] / 5 * diff_count});
      }
    }
  }

  int now_a, now_b, value;
  for (int i = 0; i < change.size(); i++) {
    now_a = change[i].first.first;
    now_b = change[i].first.second;
    value = change[i].second;
    room[now_a][now_b] += value;
  }
}

void ac_func() {
  // 공기청정기 윗부분
  int now_a = ac[0];
  int now_b = 0;

  int next_a, next_b;
  int index = 0; // 방향 전환용 인덱스
  while(true) {
    next_a = now_a + ac0_da[index];
    next_b = now_b + ac0_db[index];
    
    if (0 > next_a || next_a > ac[0] || 0 > next_b || next_b >= C) {
      index++; // 범위를 이탈할 경우
    } 
    else {
      if (room[now_a][now_b] == -1) { // 시작지점일 경우
        now_a = next_a;
        now_b = next_b;
        continue;
      }

      if (next_a == ac[0] && next_b == 0) { // 종료지점일 경우
        room[now_a][now_b] = 0;
        break;
      }

      room[now_a][now_b] = room[next_a][next_b];
      now_a = next_a;
      now_b = next_b;
    }
  }

  // 공기청정기 아랫부분
  now_a = ac[1];
  now_b = 0;

  index = 0; // 방향 전환용 인덱스
  while(true) {
    next_a = now_a + ac1_da[index];
    next_b = now_b + ac1_db[index];

    if (ac[1] > next_a || next_a >= R || 0 > next_b || next_b >= C) {
      index++; // 범위를 이탈할 경우
    } 
    else {
      if (room[now_a][now_b] == -1) { // 시작지점일 경우
        now_a = next_a;
        now_b = next_b;
        continue;
      }

      if (next_a == ac[1] && next_b == 0) { // 종료지점일 경우
        room[now_a][now_b] = 0;
        break;
      }

      room[now_a][now_b] = room[next_a][next_b];
      now_a = next_a;
      now_b = next_b;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // R 세로, C 가로

  cin >> R >> C >> T;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> room[i][j];
      if (room[i][j] == -1) {
        ac.push_back(i); // 윗부분이 0, 아랫부분이 1로 저장
      }
    }
  }

  for (int i = 0; i < T; i++) {
    diff();
    ac_func();
  }

  int result = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (room[i][j] > 0)
        result += room[i][j];
    }
  }

  cout << result;

  return 0;
}
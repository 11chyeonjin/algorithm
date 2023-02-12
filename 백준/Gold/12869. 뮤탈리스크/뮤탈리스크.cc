#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

struct three {
  int a, b, c;
};

int N;

int user[61][61][61] = { 0, };

int tmp[3] = { 0, 0, 0 };

int attack[6][3] = {
  { 9, 3, 1 }, 
  { 9, 1, 3 },
  { 3, 9, 1 },
  { 3, 1, 9 },
  { 1, 9, 3 },
  { 1, 3, 9 }
};

queue<three> q;

int bfs() {
  while(!q.empty()) {
    int nowA = q.front().a;
    int nowB = q.front().b;
    int nowC = q.front().c;
    q.pop();
    if (user[0][0][0])
      return user[0][0][0];
    
    int nextA, nextB, nextC;
    for (int i = 0; i < 6; i++) {
      nextA = max(nowA - attack[i][0], 0);
      nextB = max(nowB - attack[i][1], 0);
      nextC = max(nowC - attack[i][2], 0);
      if (!user[nextA][nextB][nextC]) {
        q.push({nextA, nextB, nextC});
        user[nextA][nextB][nextC] = user[nowA][nowB][nowC] + 1;
      }
    }
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> tmp[i];
  }

  q.push({tmp[0], tmp[1], tmp[2]});

  cout << bfs();

  return 0;  
}
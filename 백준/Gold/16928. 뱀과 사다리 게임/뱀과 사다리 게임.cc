#include <iostream>
#include <queue>
using namespace std;

int field[101] = { 0 };

bool check[101] = { false };

int snl(int start) {
  int tmp = start;
  while(field[tmp]) {
    tmp = field[tmp];
  }
  return tmp;
}

int bfs(int start) {
  queue<pair<int, int>> q;
  q.push({start, 0});
  check[start] = true;
  while(!q.empty()) {
    int now = q.front().first;
    int how = q.front().second;
    q.pop();
    if (now == 100) {
      return how;
    }
    int next;
    for (int i = 1; i <= 6; i++) {
      next = now + i;
      if (next <= 100) {
        if (!check[next]) {
          if (field[next]) { 
            q.push({snl(next), how + 1});
          }
          else { // 뱀과 사다리가 없는 경우
            q.push({next, how + 1});
            check[next] = true;
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  check[0] = true;
  
  int N, M;
  int a, b;
  cin >> N >> M;
  while(N--) {
    cin >> a >> b;
    field[a] = b;
  }
  while(M--) {
    cin >> a >> b;
    field[a] = b;
  }

  cout << bfs(1);

  return 0;
}
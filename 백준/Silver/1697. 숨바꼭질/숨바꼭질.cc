#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> user(200001);
bool check[200001] = { 0 };

void bfs(int where, int K) {
  queue<int> q;
  q.push(where);
  check[where] = true;
  while(!q.empty()) {
    int now = q.front();
    if (now == K)
      break;
    q.pop();
    int next;
    if (now - 1 >= 0) {
      if (!check[now - 1]) {
        next = now - 1;
        q.push(next);
        user[next] = user[now] + 1;
        check[next] = true;
      }
    }
    if (now + 1 < 200001) {
      if (!check[now + 1]) {
        next = now + 1;
        q.push(next);
        user[next] = user[now] + 1;
        check[next] = true;
      }
    }
    if (now * 2 < 200001) {
      if (!check[now * 2]) {
        next = now * 2;
        q.push(next);
        user[next] = user[now] + 1;
        check[next] = true;
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int N, K;
  cin >> N >> K;

  bfs(N, K);
  cout << user[K];

  return 0;
}
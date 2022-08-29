#include <iostream>
#include <queue>
using namespace std;

int A, B;

int bfs(long long num, int target) {
  queue<pair<long long,int>> q;
  q.push({num, 0});
  while(!q.empty()) {
    long long now = q.front().first;
    int how = q.front().second;
    q.pop();
    if (now == B) {
      return how;
    }
    long long next;
    if (now <= B) {
      next = now * 2;
      if (next <= B) {
        q.push({next, how + 1});
      }
      next = now * 10 + 1;
      if (next <= B) {
        q.push({next, how + 1});
      }
    }
  }
  return -2;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> A >> B;
  
  cout << bfs(A, B) + 1;

  return 0;
}
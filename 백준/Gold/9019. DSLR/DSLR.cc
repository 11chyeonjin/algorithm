#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool check[10000] = { false };
int D (int n);
int S (int n);
int L (int n);
int R (int n);

void bfs (int num, int target) {
  queue<pair<int, string>> q;
  q.push({num, ""});
  check[num] = true;
  while(!q.empty()) {
    int now = q.front().first;
    string result = q.front().second;
    q.pop();
    if (now == target) {
      cout << result << "\n";
    }
    int next = D(now);
    if (!check[next]) {
      q.push({next, result + 'D'});
      check[next] = true;
    }
    next = S(now);
    if (!check[next]) {
      q.push({next, result + 'S'});
      check[next] = true;
    }
    next = L(now);
    if (!check[next]) {
      q.push({next, result + 'L'});
      check[next] = true;
    }
    next = R(now);
    if (!check[next]) {
      q.push({next, result + 'R'});
      check[next] = true;
    }
  }
}

int D (int n) {
  return n * 2 % 10000;
}

int S (int n) {
  if (n == 0) 
    return 9999;
  else
    return n -1;
}

int L (int n) {
  return n / 1000 + n % 1000 * 10;
}

int R (int n) {
  return n % 10 * 1000 + n / 10;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;
  int A, B;
  while(T--) {
    cin >> A >> B;
    bfs(A, B);
    memset(check, false, sizeof(check));
  }

  return 0;
}
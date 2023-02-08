#include <iostream>
using namespace std;

int N, M;
int r, c;
int d;

bool user[50][50] = { 0, };
bool visited[50][50] = { 0, };

int da[4] = { -1, 0, 1, 0 };
int db[4] = { 0, 1, 0, -1 };

void dMinus() {
  if (d == 0)
    d = 3;
  else
    d--;
}

void func(int a, int b) {
  visited[a][b] = true;
  int next_a, next_b;
  int now = d;
  do {
    dMinus();
    next_a = a + da[d];
    next_b = b + db[d];
    if (!user[next_a][next_b] && !visited[next_a][next_b]) {
      func(next_a, next_b);
      return;
    }
  } while(d != now);
  dMinus();
  dMinus();
  next_a = a + da[d];
  next_b = b + db[d];
  if (!user[next_a][next_b]) {
    dMinus();
    dMinus();
    func(next_a, next_b);
  }
  else {
    return;
  }
}

int main() {
  cin >> N >> M;
  cin >> r >> c >> d;
  
  int tmp;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> tmp;
      user[i][j] = tmp;
    }
  }

  func(r, c);

  int result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (visited[i][j])
        result++;
    }
  }

  cout << result;

  return 0;
}
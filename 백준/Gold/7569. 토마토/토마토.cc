#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

int M, N, H;

int tomato[100][100][100];
bool check[100][100][100] = { 0 };
int how[100][100][100] = { 0 };

int da[6] = { 1, -1, 0, 0, 0 , 0 };
int db[6] = { 0, 0, 1, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> q;

void bfs() {
  while(!q.empty()) {
    int now_h = get<0>(q.front());
    int now_a = get<1>(q.front());
    int now_b = get<2>(q.front());
    q.pop();
    tomato[now_h][now_a][now_b] = 1;
    for (int i = 0; i < 6; i++) {
      int next_h = now_h + dh[i];
      int next_a = now_a + da[i];
      int next_b = now_b + db[i];
      if (0 <= next_h && next_h < H && 0 <= next_a && next_a < N && 0 <= next_b && next_b < M) {
        if (tomato[next_h][next_a][next_b] == 0 && !check[next_h][next_a][next_b]) {
          q.push(make_tuple(next_h, next_a, next_b));
          check[next_h][next_a][next_b] = true;
          how[next_h][next_a][next_b] = how[now_h][now_a][now_b] + 1;
        }
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> M >> N >> H;
  
  int in;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        cin >> in;
        tomato[i][j][k] = in;
        if (in == 1) {
          q.push(make_tuple(i, j, k));
          check[i][j][k] = true;
        }
      }
    }
  }

  bfs();

  //   for (int i = 0; i < H; i++) {
  //   for (int j = 0; j < N; j++) {
  //     for (int k = 0; k < M; k++) {
  //       cout << tomato[i][j][k] << " ";
  //     }
  //   }
  // }
  
  int max = -1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < N; j++) {
      for (int k = 0; k < M; k++) {
        if (!tomato[i][j][k]) {
          cout << -1;
          return 0;
        }
        if (how[i][j][k] > max) {
          max = how[i][j][k];
        }
      }
    }
  }

  cout << max;
  return 0;
}
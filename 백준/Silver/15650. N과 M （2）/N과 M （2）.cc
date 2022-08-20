#include <iostream>
using namespace std;

int N, M;

bool visited[9] = { false };
int user[9] = { 0 };

void back_dfs(int now) {
  if (now == M) {
    bool flag = true;
    int top = -1;
    for (int i = 0; i < M; i++) {
      if (top < user[i])
        top = user[i];
      else
        flag = false;
    }
    if (flag) {
      for (int i = 0; i < M; i++) {
        cout << user[i] << " ";
      }
      cout << "\n";
    }
  }
  else {
    for (int i = 1; i <= N; i++) {
      if (!visited[i]) {
        user[now] = i;
        visited[i] = true;
        back_dfs(now + 1);
        visited[i] = false;
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  
  back_dfs(0);
  return 0;
}
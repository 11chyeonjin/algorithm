#include <iostream>
using namespace std;

int N, M;

bool visited[9];
int user[9];

void back_dfs(int count, int now) {
  if (count == M) {
    for (int i = 0; i < count; i++) {
      cout << user[i] << " ";
    }
    cout << "\n";
  }
  else {
    for (int i = now; i <= N; i++) {
      if (!visited[i]) 
      {
        user[count] = i;
        visited[i] = true;
        back_dfs(count + 1, i + 1);
        visited[i] = false;
      }
    }
  }
}


int main() {
  cin >> N >> M;

  back_dfs(0, 1);

  return 0;
}
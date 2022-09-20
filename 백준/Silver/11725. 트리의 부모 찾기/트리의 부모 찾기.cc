#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N;
vector<int> user[100001];
int parents[100001] = {0};
bool visited[100001] = {false};

queue<int> q;

void bfs(int start) {
  q.push(start);
  visited[start] = true;
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = 0; i < user[now].size(); i++) {
      int next = user[now][i];
      if (!visited[next]) {
        q.push(next);
        parents[next] = now;
        visited[next] = true;
      }
    }
  }
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  int in1, in2;
  for (int i = 0; i < N - 1; i++) {
    cin >> in1 >> in2;
    user[in1].push_back(in2);
    user[in2].push_back(in1);
  }

  bfs(1);

  for (int i = 2; i <= N; i++) {
    cout << parents[i] << "\n";
  }

  return 0;
}
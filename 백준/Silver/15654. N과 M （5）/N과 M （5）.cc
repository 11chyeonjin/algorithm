#include <iostream>
#include <algorithm>
using namespace std;

int N, M;

bool compare(int a, int b) {
  return a < b;
}

int library[9];
int visited[9];

int user[9];

void dfs(int count)
{
  if (count == M) {
    for (int i = 0; i < M; i++) {
      cout << user[i] << " ";
    }
    cout << "\n";
  }
  else {
    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        user[count] = library[i];
        visited[i] = true;
        dfs(count + 1);
        visited[i] = false;
      }
    }
  }
}

int main() {
  cin >> N >> M;
  int in;
  for (int i = 0; i < N; i++) {
    cin >> in;
    library[i] = in;
  }
  sort(library, library + N, compare);
  
  dfs(0);
  
  return 0;
}
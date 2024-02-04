#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, K;

int main() {
  cin >> N >> K;

  queue<int> q;
  vector<int> result;
  
  for (int i = 1; i <= N; i++) {
    q.push(i);
  }

  while(!q.empty()) {
    int tmp;
    for (int i = 1; i < K; i++) {
      tmp = q.front();
      q.pop();
      q.push(tmp);
    }
    tmp = q.front();
    q.pop();
    result.push_back(tmp);
  }

  cout << "<";
  for (int i = 0; i < result.size() - 1; i++) {
    cout << result[i] << ", ";
  }
  cout << result[result.size() - 1] << ">";

  return 0;
}
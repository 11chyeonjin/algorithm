#include <iostream>
#include <stack>
using namespace std;

int N;
int user[1000001];
int result[1000001];
stack<int> s; // 결과에 포함될 내림차순 스택

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N;
  int tmp;
  for (int i = 1; i <= N; i++) {
    cin >> user[i];
  }

  for (int i = N; i > 0; i--) {
    while (!s.empty() && user[i] >= s.top()) {
      s.pop();
    }
    if (s.empty()) {
      result[i] = -1;
    }
    else { // s가 빈 상태가 아니라면.
      result[i] = s.top();
    }
    s.push(user[i]);
  }

  for (int i = 1; i <= N; i++) {
    cout << result[i] << " ";
  }

  return 0;
}
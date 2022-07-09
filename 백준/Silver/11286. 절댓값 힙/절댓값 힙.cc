#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

struct comp {
  bool operator() (int a, int b) {
  if (abs(a) == abs(b))
    return a > b;
  else
    return abs(a) > abs(b);
  }
};

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  priority_queue<int, vector<int>, comp> user;

  int N;
  cin >> N;
  int in;
  for (int i = 0; i < N; i++) {
    cin >> in;
    if (in == 0) {
      if (user.size() == 0) {
        cout << 0 << "\n";
      }
      else {
        cout << user.top() << "\n";
        user.pop();
      }
    }
    else {
      user.push(in);
    }
  }
  return 0;
}
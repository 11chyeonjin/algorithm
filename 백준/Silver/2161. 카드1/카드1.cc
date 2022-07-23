#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  deque<int> user;
  
  int N;
  cin >> N;

  for (int i = N; i >= 1; i--) {
    user.push_back(i);
  }

  for (int i = 0; i < N - 1; i++) {
    cout << user.back() << " ";
    user.pop_back();
    user.push_front(user.back());
    user.pop_back();
  }
  cout << user.back();

  return 0;
}
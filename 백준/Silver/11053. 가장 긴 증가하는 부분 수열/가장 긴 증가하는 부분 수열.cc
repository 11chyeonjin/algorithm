#include <iostream>
#include <vector>
using namespace std;

// O(n^2)
int N;

vector<pair<int, int>> user; // first는 값, second는 부분 수열 길이 dp

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N;
  int in;
  for (int i = 0; i < N; i++) {
    cin >> in;
    user.push_back({in, 1});
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (user[j].first < user[i].first) {
        user[i].second = max(user[i].second, user[j].second + 1);
      }
    }
  }

  int result = -1;
  for (int i = 0; i < N; i++) {
    result = max(result, user[i].second);
  }

  cout << result;
  return 0;
}
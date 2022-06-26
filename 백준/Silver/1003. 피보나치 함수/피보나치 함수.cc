#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T = 0;
  cin >> T;

  vector<pair<int, int>> user;
  vector<pair<int, int>> result;  
  user.push_back({1, 0});
  user.push_back({0, 1});

  for (int i = 2; i < 41; i++) {
    user.push_back({user[i - 1].first + user[i - 2].first, user[i - 1].second + user[i - 2].second});
  }
  
  int pibo = 0;
  for (int i = 0; i < T; i++) {
    cin >> pibo;
    result.push_back(user[pibo]);
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i].first << " " << result[i].second << "\n";
  }

  return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;

  vector<int> user;
  int user_in;
  for (int i = 0; i < N; i++) {
    cin >> user_in;
    user.push_back(user_in);
  }
  sort(user.begin(), user.end());

  for (int i = 0; i < user.size(); i++) {
    cout << user[i] << "\n";
  }

  return 0;
}
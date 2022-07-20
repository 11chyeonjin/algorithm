#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> user;
  vector<int> sortuser;

  int x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    user.push_back(x);
    sortuser.push_back(x);
  }

  sort(sortuser.begin(), sortuser.end());
  sortuser.erase(unique(sortuser.begin(), sortuser.end()), sortuser.end());

  for (int i = 0; i < user.size(); i++) {
    cout << lower_bound(sortuser.begin(), sortuser.end(), user[i]) - sortuser.begin() << " ";
  }

  return 0;
}
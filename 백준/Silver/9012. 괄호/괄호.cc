#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int N;
  cin >> N;

  vector<string> result;

  string user;
  int check;
  for (int i = 0; i < N; i++) {
    check = 0;
    cin >> user;
    for (int j = 0; j < user.size(); j++) {
      if (user[j] == '(') {
        check++;
      }
      else {
        check--;
        if (check < 0)
          break;
      }
    }
    if (check == 0)
      result.push_back("YES");
    else
      result.push_back("NO");
  }
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }

  return 0;
}
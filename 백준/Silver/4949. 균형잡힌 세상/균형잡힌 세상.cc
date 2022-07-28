#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<string> result;
  vector<char> test;
  
  string user;
  
  while(1) {
    getline(cin, user);
    if (user[0] == '.')
      break;
    int flag = 0;
    for (int i = 0; i < user.size(); i++) {
      if (user[i] == '(') {
        test.push_back('(');
      }
      else if (user[i] == '[') {
        test.push_back('[');
      }
      else if (user[i] == ')') {
        if (test.empty()) {
          flag = 1;
          break;
        }
        if (test.back() == '(')
          test.pop_back();
        else {
          flag = 1;
          break;
        }
      }
      else if (user[i] == ']') {
        if (test.empty()) {
          flag = 1;
          break;
        }
        if (test.back() == '[')
          test.pop_back();
        else {
          flag = 1;
          break;
        }
      }
    }
    if (!test.empty())
      flag = 1;
    if (flag)
      result.push_back("no");
    else
      result.push_back("yes");
    test.clear();
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }
  
  return 0;
}
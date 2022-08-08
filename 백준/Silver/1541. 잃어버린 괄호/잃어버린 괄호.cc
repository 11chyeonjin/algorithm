#include <iostream>
#include <string>
using namespace std;

int main() {
  string user;
  cin >> user;
  string strtmp = "";
  int result = 0;
  bool flag = false;
  for (int i = 0; i <= user.size(); i++) {
    if (user[i] == '-' || user[i] == '+' || i == user.size()) {
      
      if (!flag)
        result += stoi(strtmp);
        
      else
        result -= stoi(strtmp);
      
      strtmp = "";
    }
    else {
      strtmp += user[i];
    }

    if (user[i] == '-')
        flag = true;
  }

  cout << result;
  return 0;
}
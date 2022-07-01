#include <iostream>
#include <string>
using namespace std;

int main() {
  string user;
  getline(cin, user);
  int count = 1;
  if ((user.size() == 1) && (user[0] == ' ')) {
    cout << 0;
    return 0;
  }
  for (int i = 1; i < user.size() - 1; i++) {
    if (user[i] == ' ')
      count++;
  }
  cout << count;
  return 0;
}
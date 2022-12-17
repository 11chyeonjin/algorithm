#include <iostream>
using namespace std;

int main() {
  string user;
  cin >> user;

  int str_size = user.size();
  int result = 1;

  for (int i = 0; i < str_size; i++) {
    if (user[i] != user[str_size - 1 - i]) {
      result = 0;
      break;
    }
  }

  cout << result;
  return 0;
}
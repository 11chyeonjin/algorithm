#include <iostream>
using namespace std;

int user[3];

int main() {
  for (int i = 0; i < 3; i++) {
    cin >> user[i];
  }

  if (user[0] == user[1] && user[1] == user[2]) {
    cout << user[0] * 1000 + 10000;
    return 0;
  }

  if (user[0] == user[1]) {
    cout << user[0] * 100 + 1000;
  }
  else if (user[0] == user[2]) {
    cout << user[0] * 100 + 1000;
  }
  else if (user[1] == user[2]) {
    cout << user[1] * 100 + 1000;
  }
  else {
    cout << max(user[0], max(user[1], user[2])) * 100;
  }

  return 0;
}
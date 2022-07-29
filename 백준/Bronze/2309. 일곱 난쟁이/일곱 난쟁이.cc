#include <iostream>
#include <algorithm>
using namespace std;

int user[9];

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int in;
  int sum = 0;
  for (int i = 0; i < 9; i++) {
    cin >> in;
    user[i] = in;
    sum += in;
  }
  sort(user, user+9);
  int sol = sum - 100;
  int flag = 0;
  int one, two;
  for (int i = 0; i < 9; i++) {
    if (flag)
      break;
    for (int j = i+1; j < 9; j++) {
      if (user[i] + user[j] == sol) {
        one = i;
        two = j;
        flag = 1;
        break;
      }
    }
  }
  for (int i = 0; i < 9; i++) {
    if (i == one || i == two)
      continue;
    else {
      cout << user[i] << "\n";
    }
  }
  return 0;
}
#include <iostream>
using namespace std;

int main() {
  int user;
  cin >> user;
  user = 1000 - user;
  
  int result = 0;
  result += user / 500;
  user %= 500;

  result += user / 100;
  user %= 100;

  result += user / 50;
  user %= 50;

  result += user / 10;
  user %= 10;

  result += user / 5;
  user %= 5;

  result += user;

  cout << result;

  return 0;
}
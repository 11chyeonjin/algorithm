#include <iostream>
using namespace std;

char Rot13(char alpha) {
  if (alpha >= 'A' && alpha <= 'Z') {
    if (alpha + 13 > 'Z')
      return static_cast<char>(alpha - 13);
    else
      return static_cast<char>(alpha + 13);
  }
  else {
    if (alpha + 13 > 'z')
      return static_cast<char>(alpha - 13);
    else
      return static_cast<char>(alpha + 13);
  }
}

int main() {
  string user;
  getline(cin, user);

  for (int i = 0; i< user.size() ; i++) {
    if ((user[i] >= 'A' && user[i] <= 'Z') || (user[i] >= 'a' && user[i] <= 'z')) {
      cout << Rot13(user[i]);
    }
    else
      cout << user[i];
  }

  return 0;
}
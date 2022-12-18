#include <iostream>
using namespace std;

int alpha[26] = { 0 };

int main() {
  string name;
  cin >> name;

  for (int i = 0; i < name.size(); i++) {
    alpha[name[i] - 'A']++;
  }

  int odd = -1;
  bool isOdd = false;
  for (int i = 0; i < 26; i++) {
    if (alpha[i] % 2) {
      if (isOdd) {
        cout << "I'm Sorry Hansoo";
        return 0;
      }
      else {
        isOdd = true;
        odd = i;
      }
    }
  }

  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < (alpha[i] / 2); j++) {
      cout << (char)(i + 'A');
    }
  }
  
  if (isOdd)
    cout << (char)(odd + 'A');
  
  for (int i = 25; i >= 0; i--) {
    for (int j = 0; j < (alpha[i] / 2); j++) {
      cout << (char)(i + 'A');
    }
  }
  
  return 0;
}
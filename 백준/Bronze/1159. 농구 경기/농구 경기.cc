#include <iostream>
using namespace std;

int alpha[26] = { 0 };

int main() {
  int num;
  cin >> num;
  string tmp;
  while(num--) {
    cin >> tmp;
    alpha[tmp[0] - 'a']++;
  }
  string result = "";
  
  for (int i = 0; i < 26; i++) {
    if (alpha[i] >= 5)
      result += (char)(i + 'a');
  }

  if (!result.size())
    cout << "PREDAJA";
  else
    cout << result;

  return 0;
}
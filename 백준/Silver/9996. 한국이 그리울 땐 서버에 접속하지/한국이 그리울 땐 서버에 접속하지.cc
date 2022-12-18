#include <iostream>
#include <vector>
using namespace std;

vector<bool> result;

int main() {
  int file_num;
  cin >> file_num;

  string pattern;
  cin >> pattern;

  int asterisk = pattern.find('*');

  string pront = pattern.substr(0, asterisk);
  string back = pattern.substr(asterisk + 1);

  string tmp;
  for (int i = 0; i < file_num; i++) {
    cin >> tmp;
    if (tmp.size() < pattern.size() - 1) {
      result.push_back(false);
      continue;
    }
    if ((tmp.substr(0, pront.size()) == pront) && (tmp.substr(tmp.size() - back.size()) == back))
      result.push_back(true);
    else
      result.push_back(false);
  }

  for (int i = 0; i < result.size(); i++) {
    if (result[i])
      cout << "DA\n";
    else
      cout << "NE\n";
  }

  return 0;
}
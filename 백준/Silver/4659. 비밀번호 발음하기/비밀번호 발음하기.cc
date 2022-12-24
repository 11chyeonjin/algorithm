#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> user;
vector<bool> result;

char aeiou[5] = { 'a', 'e', 'i', 'o', 'u' };
char eo[2] = { 'e', 'o' };
bool isExistAeiou = false;
int countAAA = 0;
int countBBB = 0;
bool flag = 0;
char lastC = '*';

int main() {
  string tmp;
  while(true) {
    cin >> tmp;
    if (tmp == "end") {
      break;
    }
    user.push_back(tmp);
    flag = true;
    isExistAeiou = false; // 모음 포함 여부 거르기
    countAAA = 0; // 3개 연속 거르기 모음
    countBBB = 0; // 3개 연속 거르기 자음
    lastC = '*'; // 연속 2개 거르기
    for (int i = 0; i < tmp.size(); i++) {
      if (find(eo, eo + 2, tmp[i]) == eo + 2) {
        if (lastC == tmp[i]) {
          flag = !flag;
          break;
        }
        else {
          lastC = tmp[i];
        }
      }
      if (find(aeiou, aeiou + 5, tmp[i]) != aeiou + 5) {
        isExistAeiou = true;
        countBBB = 0;
        countAAA++;
      } else {
        countAAA = 0;
        countBBB++;
      }
      if (countAAA == 3 || countBBB == 3) {
        flag = !flag;
        break;
      }
    }
    if (flag && isExistAeiou)
      result.push_back(true);
    else
      result.push_back(false);
  }

  for (int i = 0; i < result.size(); i++) {
    if (result[i]) {
      cout << "<" << user[i] << "> is acceptable.\n";
    }
    else {
      cout << "<" << user[i] << "> is not acceptable.\n";
    }
  }

  return 0;
}
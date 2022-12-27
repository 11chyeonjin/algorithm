#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> user;
int N;

bool comp(string a, string b) {
  if (a.size() == b.size())
    return a < b;
  else 
    return a.size() < b.size();
}

int main() {
  cin >> N;

  for (int i = 0; i < N; i++) {
    string in;
    cin >> in;
    
    string tmp = "";
    for (int i = 0; i < in.size(); i++) {
      if (in[i] >= '0' && in[i] <= '9') {
        tmp += in[i];
      }
      else { // 숫자가 아닐 때.
        if (tmp.size()) {
          int I = 0;
          while(tmp[I] == '0') {
            I++;
          }
          if (I) {
            tmp.erase(0, I);
          }
          if (!tmp.size())
            tmp = "0";
          user.push_back(tmp);
          tmp = "";
        }
      }
    }
    if (tmp.size()) {
      int I = 0;
      while(tmp[I] == '0') {
        I++;
      }
      if (I) {
        tmp.erase(0, I);
      }
      if (!tmp.size())
            tmp = "0";
      user.push_back(tmp);
      tmp = "";
    }
  }
  sort(user.begin(), user.end(), comp);

  for (int i = 0; i < user.size(); i++) {
    cout << user[i] << "\n";
  }

  return 0;
}
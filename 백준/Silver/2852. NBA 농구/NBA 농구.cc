#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N;
vector<pair<int,int>> user; // A-B 스코어 차이, 초

int main() {
  cin >> N;
  int team;
  string tmp;
  int now_second;
  int A = 0, B = 0;
  user.push_back({0, 0});
  for (int i = 0; i < N; i++) {
    cin >> team >> tmp;
    if (team == 1)
      A++;
    else
      B++;
    now_second = stoi(tmp.substr(0, 2)) * 60 + stoi(tmp.substr(3, 2));
    user.push_back({A - B, now_second});
  }
  user.push_back({0, 2880});

  int Atime = 0;
  int Btime = 0;
  for (int i = 0; i < user.size(); i++) {
    if (user[i].first > 0) {
      Atime += user[i + 1].second - user[i].second;
    }
    else if (user[i].first < 0) {
      Btime += user[i + 1].second - user[i].second;
    }
  }

  vector<string> result;
  
  result.push_back(to_string(Atime / 60));
  result.push_back(to_string(Atime % 60));
  result.push_back(to_string(Btime / 60));
  result.push_back(to_string(Btime % 60));

  for (int i = 0; i < 4; i++) {
    if (result[i].size() == 1) {
      result[i] = "0" + result[i];
    }
  }

  cout << result[0] << ":" << result[1] << "\n";
  cout << result[2] << ":" << result[3];
  
  return 0;
}
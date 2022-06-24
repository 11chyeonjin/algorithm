#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compare_(string a, string b){
  if(a.length() == b.length())
    return a < b;
  return a.length() < b.length();
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  vector<string> user;

  int N;
  cin >> N;
  string str_input;
  
  for (int i = 0; i < N; i++) {
    cin >> str_input;
    if (find(user.begin(), user.end(), str_input) == user.end())
      user.push_back(str_input);
  }

  sort(user.begin(), user.end(), compare_);
  
  for (int i = 0; i < user.size(); i++) {
    cout << user[i] << "\n";
  }

  return 0;
}
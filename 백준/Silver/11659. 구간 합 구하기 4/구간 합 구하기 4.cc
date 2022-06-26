#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N = 0;
  cin >> N;
  int M = 0;
  cin >> M;
  vector <int> user;
  vector <int> result;
  int num_input = 0;

  int sum = 0;
  
  for (int i = 0; i < N; i++) {
    cin >> num_input;
    sum += num_input;
    user.push_back(sum);
  }

  int minus = 0;
  int userwant = 0;
  
  for (int i = 0; i < M; i++) {
    cin >> minus;
    cin >> num_input;
    if (minus == 1) {
      result.push_back(user[num_input - 1]);
    }
    else
      result.push_back(user[num_input - 1] - user[minus - 2]);
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }

  return 0;
}
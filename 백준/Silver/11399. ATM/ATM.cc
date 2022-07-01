#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> list;

  int in;
  for (int i = 0; i < N; i++) {
    cin >> in;
    list.push_back(in);
  }

  sort(list.begin(), list.end());

  int sum = 0;
  int result = 0;
  for (int i = 0; i < list.size(); i++) {
    sum += list[i];
    result += sum;
  }

  cout << result;
  return 0;
}
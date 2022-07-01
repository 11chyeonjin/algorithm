#include <iostream>
#include <vector>
using namespace std;

int main() {
  int a, b;
  vector<int> result;
  while(!(cin >> a >> b).eof()) {
    result.push_back(a + b);
  }
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }

  return 0;
}
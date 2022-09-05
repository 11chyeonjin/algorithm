#include <iostream>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  string in;

  int result = 0;
  
  for (int i = 0; i < 8; i++) {
    cin >> in;
    for (int j = 0; j < 8; j++) {
      if (in[j] == 'F' && (i + j) % 2 == 0)
        result++;
    }
  }

  cout << result;
  return 0;
}
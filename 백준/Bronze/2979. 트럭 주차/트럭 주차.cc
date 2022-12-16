#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  int count[101] = { 0 };
  
  int one_s, one_e, two_s, two_e, three_s, three_e;
  cin >> one_s >> one_e;
  cin >> two_s >> two_e;
  cin >> three_s >> three_e;

  for (int i = 1; i <= 100; i++) {
    if (i >= one_s && i < one_e)
      count[i]++;
    if (i >= two_s && i < two_e)
      count[i]++;
    if (i >= three_s && i < three_e)
      count[i]++;
  }
  
  int result = 0;
  for (int i = 1; i <= 100; i++) {
    if (count[i] == 3)
      result += 3 * C;
    else if (count[i] == 2)
      result += 2 * B;
    else if (count[i] == 1)
      result += A;
  }

  cout << result;
  return 0;
}
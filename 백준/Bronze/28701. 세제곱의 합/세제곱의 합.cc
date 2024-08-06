#include <iostream>
#include <vector>
using namespace std;

int N;

int main() { 
  cin >> N;

  vector<int> v(2, 0);
  
  for (int i = 1; i <= N; i++) {
    v[0] += i;
    v[1] += i * i * i;
  }

  cout << v[0] << "\n" << v[0] * v[0] << "\n" << v[1];

  return 0;
}
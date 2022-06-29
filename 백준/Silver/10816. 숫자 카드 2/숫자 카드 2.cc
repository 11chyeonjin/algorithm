#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N;
  cin >> N;

  vector <int> library(20000001);
  vector <int> result;
  
  int num_in = 0;
  for (int i = 0; i < N; i++) {
    cin >> num_in;
    library[num_in + 10000000]++;    
  }

  int M;
  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> num_in;
    result.push_back(library[num_in + 10000000]);
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << " ";
  }

  return 0;
}
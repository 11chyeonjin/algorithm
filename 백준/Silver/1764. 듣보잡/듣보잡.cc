#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  vector<string> libN;
  vector<string> libM;
  vector<string> result;

  string userinput;
  for (int i = 0; i < N; i++) {
    cin >> userinput;
    libN.push_back(userinput);
  }
  for (int i = 0; i < M; i++) {
    cin >> userinput;
    libM.push_back(userinput);
  }
  sort(libN.begin(), libN.end());
  sort(libM.begin(), libM.end());

  for (int i = 0; i< M; i++) {
    if (binary_search(libN.begin(), libN.end(), libM[i])) {
      result.push_back(libM[i]);
    }
  }

  cout << result.size() << "\n";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }

  return 0;
}
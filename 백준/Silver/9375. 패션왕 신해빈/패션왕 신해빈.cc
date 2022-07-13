#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  
  int T;
  cin >> T;

  int n;
  string tmp_wear;
  string wear;
  map<string, int> library;
  
  while(T--) {
    cin >> n;
    library.clear();
    
    while(n--) {
      cin >> tmp_wear;
      cin >> wear;
      if (library.find(wear) == library.end()) {
        library.insert({wear, 1});
      }
      else {
        library[wear]++;
      }
    }
    
    int result = 1;
    
    for (auto i : library) {
      result *= i.second + 1;
    }
    
    cout << --result << "\n";
  }
  return 0;
}
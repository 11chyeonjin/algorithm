#include <iostream>
#include <vector>
using namespace std;

vector<int> question;
vector<int> stack;
vector<char> result;

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int n, in;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> in;
    question.push_back(in);
  }
  
  int where = 0;    // question에서 어디까지 해결하였는가를 나타내는 변수
  for (int i = 1; i <= n; i++) {
    stack.push_back(i);
    result.push_back('+');
    while(stack.back() == question[where] && where < n) {
      stack.pop_back();
      result.push_back('-'); 
      where++;
    }                            
  }
  for (int i = 0; i < stack.size(); i++) {
    if (stack.back() != question[where]) {
      cout << "NO";
      return 0;
    }
    stack.pop_back();
    result.push_back('-');
    where++;
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << "\n";
  }
  
  return 0;
}
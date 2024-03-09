#include <iostream>
#include <vector>
#include <stack>
using namespace std;

string str;

int main() {
  /*
    1. 구현으로 접근
      : 변수의 경우 나타난 순서가 변하지 않음.
      : 연산자의 경우, 스택에 자신보다 낮은 연산자를 모두 pop하고 스택에 삽입
      : 닫힌 괄호가 입력되면, 열린 괄호까지의 stack 내용물을 통해 일시적으로 완성한다.
  */
  cin >> str;

  vector<char> result;
  stack<char> s;

  for (int i = 0; i < str.size(); i++) {
    if ('A' <= str[i] && str[i] <= 'Z') {
      result.push_back(str[i]);
      continue;
    }
    
    if (s.empty()) {
      s.push(str[i]);
      continue;
    }

    if ('(' == str[i]) { // 제일 먼저 확인
      s.push(str[i]);
      continue;
    }

    if (str[i] == '+' || str[i] == '-') { // * / ( 보다 우선순위가 낮음
      while(true) {
        if (s.empty()) { // 비어있다면 바로 추가
          s.push(str[i]);
          break;
        } else if (s.top() == '(') { // 괄호라면 바로 추가
          s.push(str[i]);
          break;
        } else { // 우선순위가 같거나 높은 +-*/는 출력
          result.push_back(s.top());
          s.pop();
        }
      }
    } else if (str[i] == '*' || str[i] == '/') { // 우선순위 우선
      while(true) {
        if (s.empty()) {
          s.push(str[i]);
          break;
        } else if (s.top() == '(' || s.top() == '+' || s.top() == '-') { // 스택에 바로 추가
          s.push(str[i]);
          break;
        } else {
          result.push_back(s.top());
          s.pop();
        }
      }
    } else { // ')'
      while(true) {
        if (s.top() == '(') {
          s.pop();
          break;
        } else {
          result.push_back(s.top());
          s.pop();
        }
      }
    }
  }
  
  while(!s.empty()) {
    result.push_back(s.top());
    s.pop();
  }

  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
  }

  return 0;
}
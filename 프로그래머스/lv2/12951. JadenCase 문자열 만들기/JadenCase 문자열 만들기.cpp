#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> sol;

string solution(string s) {
    
    string tmp = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') { // 공백 문자라면
            if (tmp.size() > 0) { // 기존 tmp 문자열이 존재한다면 vector에 push
                sol.push_back(tmp);
            }
            tmp = ""; // tmp 문자열 초기화
            sol.push_back(" "); // 공백 추가!
        }  
        else { // 공백 문자열이 아니라면
            if (tmp.size() == 0) { // 첫 문자라면
                if ('a' <= s[i] && s[i] <= 'z') { // 소문자 확인 및 처리 진행
                    tmp += s[i] + 'A' - 'a';
                } else {
                    tmp += s[i];
                }
            }
            else { // 첫 문자가 아니라면
                if ('A' <= s[i] && s[i] <= 'Z') { // 대문자 확인 및 처리 진행
                    tmp += s[i] + 'a' - 'A';
                } else {
                    tmp += s[i];
                }
            }
        }
    }
    if (tmp.size() > 0)
        sol.push_back(tmp);
    
    string answer = "";
    
    for (int i = 0; i < sol.size(); i++) {
        answer += sol[i];
    }
    
    return answer;
}
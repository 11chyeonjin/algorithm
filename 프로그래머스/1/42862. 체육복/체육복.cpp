#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> students(n, 1);
    
    for (int i = 0; i < lost.size(); i++) {
        students[lost[i] - 1]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        students[reserve[i] - 1]++;
    }
    
    int frontI, backI;
    for (int i = 0; i < n; i++) {
        
        // 앞 뒤 인덱스 변수
        frontI = i - 1;
        backI = i + 1;
        
        if (students[i] == 2) {
            if (frontI >= 0 && students[frontI] == 0) {
                // 빌려줄 수 있는 경우
                students[frontI]++;
                students[i]--;
                continue;
            }
            if (backI < n && students[backI] == 0) {
                // 빌려줄 수 있는 경우
                students[backI]++;
                students[i]--;
                continue;
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (students[i])
            answer++;
        cout << students[i] << " ";
    }
    
    return answer;
}
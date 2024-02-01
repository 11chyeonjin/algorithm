#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int n1, int n2) {
    return n1 > n2;
}

int solution(vector<int> A, vector<int> B) {
    // 1. 그리디로 접근
    // 1.1. 어떻게 해도 이기지 못할 경우, B 팀은 최약자를 내보내는 방식 사용 => 여러 포인터 사용
    sort(A.begin(), A.end(), comp);
    sort(B.begin(), B.end(), comp);
    
    
    int answer = 0;
    
    int b_index = B.size() - 1;
    int a_index = A.size() - 1;
    int a_reverse_index = 0;
    
    while(a_index >= a_reverse_index && b_index >= 0) {
        if (B[b_index] > A[a_index]) { // B팀 승리
            answer++;
            a_index--;
            b_index--;
        } else {
            b_index--;
            a_reverse_index++;
        }
    }
    
    return answer;
}
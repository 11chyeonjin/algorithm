#include <string>
#include <vector>
using namespace std;

int dp[2001] = { 0, };

void jump (int num) {
    dp[num] = (dp[num - 1] + dp[num - 2]) % 1234567;
    // 한 칸 점프로 가는 방법 + 두 칸 점프로 가는 방법
}

long long solution(int n) {
    
    dp[1] = 1; // 1칸 점프로만 가능
    dp[2] = 2; // 1칸 점프로만으로도, 2칸 점프로만으로도 가능
    
    for (int i = 3; i <= n; i++) {
        jump(i);
    }
    
    long long answer = 0;
    answer = dp[n] % 1234567;
    return answer;
}
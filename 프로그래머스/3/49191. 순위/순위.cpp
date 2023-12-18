#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define INF 987654321
using namespace std;

bool fight[101][101] = { false, }; // 선수의 순위 파악을 위한 배열. 값은 서열을 알 수 있는 사람의 수

int solution(int n, vector<vector<int>> results) {
    for (int i = 0; i < results.size(); i++) {
        fight[results[i][0]][results[i][1]] = true;
        // fight[results[i][1]][results[i][0]] = true; 중요! 이게 있으면 안됨. 앙방향이 아님
    }
    
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (fight[i][k] && fight[k][j]) {
                    fight[i][j] = true;
                    // fight[j][i] = true; 중요! 이게 있으면 안됨!
                }
            }
        }
    }
    
    int answer = 0;
    
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            if (fight[i][j] || fight[j][i]) {
                cnt++;
            } else
                continue;
        }
        if (cnt == n - 1) {
            answer++;
            cout << cnt << " " << i << "\n";
        }
            
    }
    
    return answer;
}
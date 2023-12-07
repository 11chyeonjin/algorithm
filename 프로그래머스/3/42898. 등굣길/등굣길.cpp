#include <string>
#include <vector>

using namespace std;

long long sol[101][101] = { 0, }; // 물 웅덩이 -1, 경계값에 주의

int solution(int m, int n, vector<vector<int>> puddles) {
    
    for (int i = 0; i < puddles.size(); i++) {
        sol[puddles[i][0]][puddles[i][1]] = -1;
    }
    
    sol[1][0] = 1;
    int left, top;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (sol[i][j] == -1)
                continue;
            top = (sol[i - 1][j] == -1) ? 0 : sol[i - 1][j];
            left = (sol[i][j - 1] == -1) ? 0 : sol[i][j - 1];
            sol[i][j] = (left + top) % 1000000007;
        }
    }
    
    return sol[m][n];
}
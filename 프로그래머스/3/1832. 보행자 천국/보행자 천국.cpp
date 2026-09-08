#include <iostream>
#include <vector>
using namespace std;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };
int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city) {
    vector<vector<pair<int,int>>> v(m, vector<pair<int,int>>(n, {0, 0})); // 우측, 하측
    
    v[0][0] = {0, 1};
    
    for (int y = 0; y < m; y++) {
        // 우측 이동
        for (int x = 0; x < n - 1; x++) {
            // 이전 혹은 다음 위치가 통금
            if (city[y][x] == 1 || city[y][x + 1] == 1) {
                continue;
            }
            
            v[y][x + 1].first += v[y][x].first;
            
            if (city[y][x] != 2) {
                v[y][x + 1].first += v[y][x].second;
            }
            
            v[y][x + 1].first %= MOD;
        }
        
        // 마지막 줄 하방이동은 제외
        if (y == m - 1) {
            break;
        }
        
        // 하방 이동
        for (int x = 0; x < n; x++) {
            if (city[y][x] == 1 || city[y + 1][x] == 1) {
                continue;
            }
            
            v[y + 1][x].second += v[y][x].second;
            
            if (city[y][x] != 2) {
                v[y + 1][x].second += v[y][x].first;
            }
            
            v[y + 1][x].second %= MOD;
        }
    }
    
    // for (int i = 0; i < m; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << v[i][j].first << "," << v[i][j].second << " ";
    //     }
    //     cout << "\n";
    // }
    
    return (v[m - 1][n - 1].first + v[m - 1][n - 1].second) % MOD;
}
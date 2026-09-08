#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

int bfs(int y, int x, vector<vector<int>> &picture, vector<vector<bool>> &visited, int m, int n) {
    int color = picture[y][x];
    
    int rst = 0;
    
    queue<pair<int,int>> q;
    q.push({y, x});
    visited[y][x] = true;
    
    while(!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        rst++;
        
        for (int i = 0; i < 4; i++) {
            int nextY = cur.first + dy[i];
            int nextX = cur.second + dx[i];
            
            if (0 <= nextY && nextY < m && 0 <= nextX && nextX < n) {
                if (picture[nextY][nextX] == color && !visited[nextY][nextX]) {
                    q.push({nextY, nextX});
                    visited[nextY][nextX] = true;
                }
            }
        }
    }
    
    return rst;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (picture[y][x] != 0 && !visited[y][x]) {
                number_of_area++;
                int curRst = bfs(y, x, picture, visited, m, n);
                max_size_of_one_area = max(max_size_of_one_area, curRst);
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
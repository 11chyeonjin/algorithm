#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> computers_glob;
vector<bool> visited;

void dfs(int num, int n) { // num : 현재 컴퓨터, n : 전체 컴퓨터 수
    visited[num] = true;
    
    for (int i = 0; i < n; i++) {
        if (computers_glob[num][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    computers_glob = computers;
    visited.resize(n, false);
    
    int answer = 0;
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n);
            answer++;
        }
    }
    
    return answer;
}
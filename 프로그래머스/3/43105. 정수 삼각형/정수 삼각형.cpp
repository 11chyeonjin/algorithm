#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = 1; i < triangle.size(); i++) {
        triangle[i][0] += triangle[i - 1][0];
        for (int j = 1; j < triangle[i].size() - 1; j++) {
            triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
        }
        triangle[i][i] += triangle[i - 1][i - 1];
    }
    
    int answer = -1;
    
    for (int i = 0; i < triangle.size(); i++) {
        answer = max(answer, triangle[triangle.size() - 1][i]);
    }
    
    return answer;
}
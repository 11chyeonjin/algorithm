#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<char>> v(30);

// 9시부터 시계방향으로 8 방향 순회 방향성 제시
int da[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
int db[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }; 

bool remove_func(int m, int n) {
    vector<pair<int,int>> remove_result;
    
    for (int now_a = 1; now_a < m - 1; now_a++) {
        for (int now_b = 1; now_b < n - 1; now_b++) {
            
            char now_char = v[now_a][now_b];
            
            if (now_char == ' ') // 기준 칸이 공백일 경우 넘김
                continue;
            
            int next_a, next_b;
            bool flag;
            
            // 북서방향 사각형 검사
            flag = true;
            for (int i = 0; i < 3; i++) {
                next_a = now_a + da[i];
                next_b = now_b + db[i];
                if (v[next_a][next_b] != now_char) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                remove_result.push_back({now_a, now_b});
                for (int i = 0; i < 3; i++) {
                    next_a = now_a + da[i];
                    next_b = now_b + db[i];
                    remove_result.push_back({next_a, next_b});
                }
            }
                
            // 북동방향 사각형 검사
            flag = true;
            for (int i = 2; i < 5; i++) {
                next_a = now_a + da[i];
                next_b = now_b + db[i];
                if (v[next_a][next_b] != now_char) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                remove_result.push_back({now_a, now_b});
                for (int i = 2; i < 5; i++) {
                    next_a = now_a + da[i];
                    next_b = now_b + db[i];
                    remove_result.push_back({next_a, next_b});
                }
            }
            
             // 남동방향 사각형 검사
            flag = true;
            for (int i = 4; i < 7; i++) {
                next_a = now_a + da[i];
                next_b = now_b + db[i];
                if (v[next_a][next_b] != now_char) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                remove_result.push_back({now_a, now_b});
                for (int i = 4; i < 7; i++) {
                    next_a = now_a + da[i];
                    next_b = now_b + db[i];
                    remove_result.push_back({next_a, next_b});
                }
            }
            
             // 남서방향 사각형 검사
            flag = true;
            for (int i = 6; i < 8; i++) {
                next_a = now_a + da[i];
                next_b = now_b + db[i];
                if (v[next_a][next_b] != now_char) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                next_a = now_a + da[0];
                next_b = now_b + db[0];
                if (v[next_a][next_b] != now_char) {
                    flag = false;
                } else {
                    remove_result.push_back({now_a, now_b});
                    remove_result.push_back({next_a, next_b});
                }
                if (flag) {
                    for (int i = 6; i < 8; i++) {
                        next_a = now_a + da[i];
                        next_b = now_b + db[i];
                        remove_result.push_back({next_a, next_b});
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < remove_result.size(); i++) {
        v[remove_result[i].first][remove_result[i].second] = ' ';
    }
    
    if (!remove_result.empty())
        return true;
    else
        return false;
}

void down_func(int m, int n) {
    for (int j = 0; j < n; j++) { // 가로 기준으로 하나하나 낙하
        for (int i = m - 1; i >= 0; i--) {
            if (v[i][j] == ' ') { // 빈 공간을 발견했다면,
                int tmp_index = i - 1;
                while(tmp_index >= 0) {
                    if (v[tmp_index][j] != ' ') { // 가장 가까운 채워진 블록이 존재한다면,
                        v[i][j] = v[tmp_index][j];
                        v[tmp_index][j] = ' '; // 즉시 블록을 내림.
                        break;
                    }
                    tmp_index--;
                }
                if (tmp_index < 0)
                    break;
            }
        }
    }
}

int solution(int m, int n, vector<string> board) {
    /*
        1. 단순 구현으로 접근
            : 세로 m, 가로 n
            : 라이언(R), 무지(M), 어피치(A), 프로도(F), 네오(N), 튜브(T), 제이지(J), 콘(C)
            : 최악의 상황에서 1000 * 10 * 1000 = 10,000,000 보다 적은 시간 복잡도를 가질 것.
    */
    
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            v[i].push_back(board[i][j]);
        }
    }

    while(remove_func(m, n)) { // 참일 경우 블록이 지워진 것을 의미
        down_func(m, n);
    }
    
    int answer = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == ' ')
                answer++;
        }
    }
    
    return answer;
}
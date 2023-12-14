#include <string>
#include <vector>
#include <stack>
#include <tuple>
#include <algorithm>
#include <iostream>
using namespace std;

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

int func(vector<string> place) {
    int pp[5][5] = { 0, };
    bool visited[5][5] = { false, };
    
    stack<tuple<int,int,int>> q;
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (place[i][j] == 'O') { // 갈 수 있는 곳은 1
                pp[i][j] = 1;
            } else if (place[i][j] == 'P') { // 인원이 있는 곳은 2
                pp[i][j] = 2;
                q.push({i, j, 0});
                // 방문처리는 일단 미루기
            }    
            else // 벽이 있는 곳은 0
                pp[i][j] = 0;
        }
    }
    
    // 이하 dfs를 응용한 구현 코드
    int now_a, now_b, deep;
    while(!q.empty()) {
        now_a = get<0>(q.top());
        now_b = get<1>(q.top());
        deep = get<2>(q.top()); // deep 0 : 인원 자리 / deep 1 : 맨해튼 1 / deep 2 : 맨해튼 2
        cout << now_a << " " << now_b << " " << deep << "\n";
        q.pop();
        visited[now_a][now_b] = true; // 이때 방문처리 - 다른 곳에서 해당 인원에게 접근하는 것은 불필요하므로 고려x
        int next_a, next_b;
        for (int i = 0; i < 4; i++) {
            next_a = now_a + da[i];
            next_b = now_b + db[i];
            if (0 <= next_a && next_a < 5 && 0 <= next_b && next_b < 5) {
                if (!visited[next_a][next_b]) { // 방문하지 않은 곳
                    if (pp[next_a][next_b] == 1) { // 빈 테이블일 경우
                        if (deep < 1) { // 더 이동 가능한 지 확인!
                            q.push({next_a, next_b, deep + 1});
                        }
                    } else if (pp[next_a][next_b] == 2) { // 응시자가 있는 경우
                        return 0;
                    }
                }
            }
        }
    }

    return 1; // 거리두기 준수가 확실한 경우!
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    for (int i = 0; i < 5; i++) {
        answer.push_back(func(places[i]));
    } 
    
    return answer;
}
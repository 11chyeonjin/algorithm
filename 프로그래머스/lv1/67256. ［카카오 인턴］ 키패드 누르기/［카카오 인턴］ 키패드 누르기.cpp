#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int keypad[4][3] =
{
    { 1, 2, 3 },
    { 4, 5, 6 },
    { 7, 8, 9 },
    { 10, 0, 11 }
};

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

int check[4][3];

int how(int now, int target) {
    memset(check, 0, sizeof(check));
    queue<pair<int, int>> q;
    bool flag = false;
    for (int i = 0; i < 4; i++) { // now 의 위치를 탐색
        for (int j = 0; j < 3; j++) {
            if (keypad[i][j] == now) {
                q.push({i, j});
                check[i][j] = 1;
                flag = true;
                break;
            }
            if (flag)
                break;
        }
    }
    while(!q.empty()) {
        int now_a = q.front().first;
        int now_b = q.front().second;
        q.pop();
        if (keypad[now_a][now_b] == target) {
            return check[now_a][now_b] - 1;
        }
        for (int i = 0; i < 4; i++) {
            int next_a = now_a + da[i];
            int next_b = now_b + db[i];
            if (0 <= next_a && next_a < 4 && 0 <= next_b && next_b < 3) {
                if (!check[next_a][next_b]) {
                    q.push({next_a, next_b});
                    check[next_a][next_b] = check[now_a][now_b] + 1;
                }
            }
        }
    }
    return -1; // 오류..
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_now = 10;
    int right_now = 11;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
            answer += 'L';
            left_now = numbers[i];
        }
        else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
            answer += 'R';
            right_now = numbers[i];
        }
        else {
            int ifleft = how(left_now, numbers[i]);
            int ifright = how(right_now, numbers[i]);
            if (ifleft == ifright) {
                if (hand == "right") {
                    answer += 'R';
                    right_now = numbers[i];
                }
                else { // hand == "left"
                    answer += 'L';
                    left_now = numbers[i];
                }
            }
            else if (ifleft > ifright) {
                answer += 'R';
                right_now = numbers[i];
            }
            else { // ifright >
                answer += 'L';
                left_now = numbers[i];
            }
        }
    }
    return answer;
}
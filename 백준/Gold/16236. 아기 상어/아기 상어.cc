#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
#include <tuple>
using namespace std;

int field[20][20];
int check[20][20] = { 0 }; // 매 bfs마다 식사를 시도하고, 따라서 매 bfs 마다
                            // 0으로 초기화를 해줘야됨

bool compare(tuple<int, int, int> t1, tuple<int, int, int> t2) { // 거리 대조
    return get<2>(t1) < get<2>(t2);
}

bool compare2(tuple<int, int, int> t1, tuple<int, int, int> t2) {
    if (get<0>(t1) == get<0>(t2)) {
        return get<1>(t1) < get<1>(t2);
    }
    else
        return get<0>(t1) < get<0>(t2);
}

int N;
int times = 0;
int sizes = 2;
int eat_amount = 0;
int a, b; // 아기 상어의 현 위치

int da[4] = { 0, 0, 1, -1 };
int db[4] = { 1, -1, 0, 0 };

// void print() {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       if (a == i && b == j) {
//         cout << "*" << " ";
//       }
//       else
//         cout << field[i][j] << " ";
//     }
//     cout << "\n";
//   }
//   cout << "이후 사이즈는 " << size << "\n";
// }


bool bfs() {
    memset(check, 0, sizeof(check));
    queue<pair<int, int>> q;
    vector<tuple<int, int, int>> fish;
    q.push({ a, b });
    check[a][b] = 1; // 실제 시간은 0이므로, 모두 -1 처리를 해줘야됨.
    while (!q.empty()) {
        int now_a = q.front().first;
        int now_b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int next_a = now_a + da[i];
            int next_b = now_b + db[i];
            if (0 <= next_a && next_a < N && 0 <= next_b && next_b < N) {
                if (sizes >= field[next_a][next_b] && !check[next_a][next_b]) {
                    q.push({ next_a, next_b });
                    check[next_a][next_b] = check[now_a][now_b] + 1;
                    if (0 < field[next_a][next_b] && field[next_a][next_b] < sizes) { // 먹을 수 있는 물고기
                        fish.push_back(make_tuple(next_a, next_b, check[next_a][next_b]));
                    }
                }
            }
        }
    }
    if (fish.size() == 1) { // 먹을 수 있는 물고기가 한마리
        int tmp_a = get<0>(fish[0]);
        int tmp_b = get<1>(fish[0]);
        field[tmp_a][tmp_b] = 0;
        a = tmp_a;
        b = tmp_b;
        times += check[tmp_a][tmp_b] - 1;
        eat_amount++;
        if (eat_amount == sizes) {
            eat_amount = 0;
            sizes++;
        }
    }
    else if (fish.size() == 0) { // 먹을 수 있는 물고기가 없다면
        return false;
    }
    else { // 먹을 수 있는 물고기가 한마리 이상이라면,
        sort(fish.begin(), fish.end(), compare);
        int min = get<2>(fish[0]);
        for (int i = fish.size() - 1; i >= 0; i--) {
            if (get<2>(fish[i]) != min) {
                fish.erase(fish.begin() + i);
            }
        }
        if (fish.size() == 1) {
            int tmp_a = get<0>(fish[0]);
            int tmp_b = get<1>(fish[0]);
            field[tmp_a][tmp_b] = 0;
            a = tmp_a;
            b = tmp_b;
            times += check[tmp_a][tmp_b] - 1;
            eat_amount++;
            if (eat_amount == sizes) {
                eat_amount = 0;
                sizes++;
            }
        }
        else {
            sort(fish.begin(), fish.end(), compare2);
            int tmp_a = get<0>(fish[0]);
            int tmp_b = get<1>(fish[0]);
            field[tmp_a][tmp_b] = 0;
            a = tmp_a;
            b = tmp_b;
            times += check[tmp_a][tmp_b] - 1;
            eat_amount++;
            if (eat_amount == sizes) {
                eat_amount = 0;
                sizes++;
            }
        }
    }
    // print();
    return true;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N;

    int in;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> in;
            if (in == 9) {
                a = i;
                b = j;
                in = 0;
            }
            field[i][j] = in;
        }
    }

    while (bfs());

    cout << times;

    return 0;
}
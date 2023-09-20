#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> p; // 프로세스 중요도 순으로 정렬된 인덱스 값. 해당 sol에서는 불변값이며, 비교 후 반복문 제어용으로 사용됨

bool comp(int a, int b) {
    return a > b;
}

int solution(vector<int> priorities, int location) {
    p = priorities;
    sort(p.begin(), p.end(), comp);

    int p_i = 0; // 프로세스 중요도 순으로 정렬된 인덱스 값. 초기값 0
    int priorities_i = 0; // 정렬되지 않은 우선순위 큐의 인덱스 값. 초기값 0
    int result = 0;

    while(p.size() > p_i) {
        if (p[p_i] == priorities[priorities_i]) { // 만약, 현재 프로세스가 중요도가 가장 높은 프로세스라면
            result ++;
            if (priorities_i == location) {
                return result;
            }
            p_i++; // 프로세스 중요도 인덱스를 ++
            priorities_i++;
        }
        else { // 만약, 현재 프로세스가 중요도가 가장 높은 프로세스가 아니라면
            priorities.push_back(priorities[priorities_i]);
            if (priorities_i == location) {
                location = priorities.size() - 1;
            }
            priorities_i++;
        }
    }
}

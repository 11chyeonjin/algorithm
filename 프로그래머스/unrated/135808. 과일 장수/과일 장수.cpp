#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) { 
  return a > b;
}

int solution(int k, int m, vector<int> score) {
    int box_num = score.size() / m;
    int trash_apple = score.size() % m;
    
    if (box_num < 1)
        return 0;
    
    sort(score.begin(), score.end(), comp);
    
    for (int i = 0; i < trash_apple; i++) {
        score.pop_back();
    }
    
    sort(score.begin(), score.end());
    
    int answer = 0;
    
    for (int i = 0; i < box_num; i++) {
        answer += score[m * i] * m;
    }
    
    return answer;
}
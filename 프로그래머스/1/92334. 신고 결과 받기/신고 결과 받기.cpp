#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool user_reports[1001][1001] = { false, }; // user_reports : 유저별 신고한 타 유저 정보
int reports[1001] = { 0, }; // reports : 유저별 신고당한 횟수

int id_func(vector<string> id_list, string users) {
    for (int i = 0; i < id_list.size(); i++) {
        if (id_list[i] == users)
            return i;
    }
    return -1;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    int users = id_list.size(); // users : 유저 수 변수
    
    for (int i = 0; i < report.size(); i++) {
        int tmp = report[i].find(' ');
        
        int reporting = id_func(id_list, report[i].substr(0, tmp)); // 신고자
        int be_reported = id_func(id_list, report[i].substr(tmp + 1)); // 피신고자
        if (!user_reports[reporting][be_reported]) {
            user_reports[reporting][be_reported] = true;
            reports[be_reported]++; 
        }
    }
    
    vector<int> real_be_reported;
    for (int i = 0; i < users; i++) {
        if (reports[i] >= k)
            real_be_reported.push_back(i);
    }
    
    vector<int> answer;
    
    int ans_tmp = 0;
    for (int i = 0; i < users; i++) {
        ans_tmp = 0;
        for (int j = 0; j < real_be_reported.size(); j++) {
            if (user_reports[i][real_be_reported[j]])
                ans_tmp++;
        }
        answer.push_back(ans_tmp);
    }
    
    return answer;
}
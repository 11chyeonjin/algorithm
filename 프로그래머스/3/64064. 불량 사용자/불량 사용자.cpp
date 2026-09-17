#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool check(string str, string mask);
void dfs(vector<set<int>>& setArr, int curI, vector<int>& tmpArr, set<string>& answerSet);

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<set<int>> setArr(banned_id.size());
    
    for (int bi = 0; bi < banned_id.size() ; bi++) {
        string b_id = banned_id[bi];
        
        for (int i = 0; i < user_id.size(); i++) {
            string id = user_id[i];
            
            if (check(id, b_id)) {
                setArr[bi].insert(i);
            }
        }
    }
    
    vector<int> tmpArr(banned_id.size());
    
    set<string> answerSet;
    
    dfs(setArr, 0, tmpArr, answerSet);
    
    return answerSet.size();
}

void dfs(vector<set<int>>& setArr, int curI, vector<int>& tmpArr, set<string>& answerSet) {
    if (curI == tmpArr.size()) {
        set<int> curSet(tmpArr.begin(), tmpArr.end());
        string rst = "";
        for (const auto& tt : curSet) {
            rst += to_string(tt);
        }
        answerSet.insert(rst);
        return;
    }
    
    for (const auto& s_el : setArr[curI]) {
        tmpArr[curI] = s_el;
        bool flag = true;
        
        for (int k = 0; k < curI; k++) {
            if (tmpArr[k] == s_el) {
                flag = false;
                break;
            }
        }
        
        if (!flag) {
            continue;
        }
        
        dfs(setArr, curI + 1, tmpArr, answerSet);
    }
}

bool check(string str, string mask) {
    bool flag = true;
    
    if (str.size() != mask.size()) {
        return false;
    }
    
    for (int i = 0; i < mask.size(); i++) {
        if (mask[i] == '*') {
            continue;
        }
        
        if (mask[i] != str[i]) {
            flag = false;
            break;
        }
    }
    
    return flag;
}

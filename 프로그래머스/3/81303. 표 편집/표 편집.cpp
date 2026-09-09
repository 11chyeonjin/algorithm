#include <string>
#include <vector>
#include <stack>
#include <set>
#include <iostream>
using namespace std;

string solution(int n, int k, vector<string> cmd) {
    string ans = "";
    vector<int> prev(n, -1);
    vector<int> post(n, -1);
    stack<int> trash;
    
    for (int i = 0; i < n; i++) {
        if (i != 0) {
            prev[i] = i - 1;
        }
        
        if (i != n - 1) {
            post[i] = i + 1;
        }
    }
    
    for (const auto& c:cmd) {
        if (c[0] == 'U') {
            int num = stoi(c.substr(2));
            
            while(num--) {
                k = prev[k];
            }
        }
        
        if (c[0] == 'D') {
            int num = stoi(c.substr(2));
            
            while(num--) {
                k = post[k];
            }
        }
        
        if (c[0] == 'C') {
            // 본인 처리
            trash.push(k);
            
            // 앞 뒤 처리
            if (prev[k] != -1) {
                post[prev[k]] = post[k];
            }
            
            if (post[k] != -1) {
                prev[post[k]] = prev[k];
            }
            
            // k 자리 파악
            if (post[k] == -1) {
                k = prev[k];
            } else {
                k = post[k];
            }
        }
        
        if (c[0] == 'Z') {
            // 복구 처리
            int tmp = trash.top();
            trash.pop();
            // 앞 뒤 처리
            if (prev[tmp] != -1) {
                post[prev[tmp]] = tmp;
            }
            
            if (post[tmp] != -1) {
                prev[post[tmp]] = tmp;
            }
            // 본인 처리
        }
    }
    
    // set을 통한 처리는 불가능
    // X로 채워진 string으로 시작해서 O로 타고 올라가면서 진행
        // 단, 시작지점을 파악할 근거가 부족함.
    
    for (int i = 0; i < n; i++) {
        ans += 'X';
    }
    
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (prev[i] != -1) {
            break;
        }
        cur = i;
    }
    ans[cur] = 'O';
    
    while(post[cur] != -1) {
        cur = post[cur];
        ans[cur] = 'O';
    }
    
    return ans;
}
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long left = 1;
    long long right = times[times.size() - 1] * (long long)n;
    long long mid;
    long long cnt;
    
    while(left <= right) {
        mid = (left + right) / 2;
        
        cnt = 0;
        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
        }
        
        if (cnt < n) {
            left = mid + 1;
        } else {
            right = mid - 1; 
            answer = mid;
        }
    }
    

    return answer;
}
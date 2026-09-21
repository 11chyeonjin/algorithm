#include <vector>
#include <string>
#include <iostream>
using namespace std;

#define INF 987654321

int solution(vector<string> arr) {
    int iiLimit = arr.size() / 2 + 1;
    
    vector<vector<int>> maxDp(iiLimit, vector<int>(iiLimit, -INF));
    vector<vector<int>> minDp(iiLimit, vector<int>(iiLimit, INF));
    
    
    for (int i = 0; i < iiLimit; i++) {
        maxDp[i][i] = stoi(arr[i * 2]);
        minDp[i][i] = stoi(arr[i * 2]);
    }
    
    for (int s = 2; s <= iiLimit; s ++) {
        for (int f = 0; f < iiLimit - s + 1; f++) {
            for (int m = f; m < f + s - 1; m++) {
                maxDp[f][f + s - 1] = max(maxDp[f][f + s - 1], (arr[m * 2 + 1] == "+") ? maxDp[f][m] + maxDp[m + 1][f + s - 1] : maxDp[f][m] - minDp[m + 1][f + s - 1]);
                minDp[f][f + s - 1] = min(minDp[f][f + s - 1], (arr[m * 2 + 1] == "+") ? minDp[f][m] + minDp[m + 1][f + s - 1] : minDp[f][m] - maxDp[m + 1][f + s - 1]);
            }
        }
    }
    
    return maxDp[0][iiLimit - 1];
}
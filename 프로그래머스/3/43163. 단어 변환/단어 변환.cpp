#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool convertFunc(string firstWord, string secondWord);

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(), false);
    
    queue<pair<string,int>> q;
    
    q.push({begin, 0});
    
    while(!q.empty()) {
        string curWord = q.front().first;
        int curCount = q.front().second;
        q.pop();
        
        if (curWord == target) {
            return curCount;
        }
        
        for (int i = 0; i < words.size(); i++) {
            if (!visited[i] && convertFunc(curWord, words[i])) {
                q.push({words[i], curCount + 1});
                visited[i] = true;
            }
        }
    }
    
    return 0;
}

bool convertFunc(string firstWord, string secondWord) {
    int count = 0;
    for (int i = 0; i < firstWord.size(); i++) {
        if (firstWord[i] != secondWord[i]) {
            count++;
        }
        
        if (count > 1) {
            return false;
        }
    }
    
    return true;
}
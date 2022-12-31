#include <iostream>
#include <algorithm>
using namespace std;

char aeiou[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };

int main() {
    string s;
    int count_i = 0;
    while(true) {
        count_i = 0;
        getline(cin, s);
        if (s == "#")
            break;
        else {
            for (int i = 0; i < s.size(); i++) {
                if (find(aeiou, aeiou + 10, s[i]) != aeiou + 10)
                    count_i++;
            }
        }
        cout << count_i << "\n";
    }
    return 0;
}
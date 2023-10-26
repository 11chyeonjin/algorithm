class Solution {
    public int solution(int n) {
        int answer = 0;
        int i = 2;
        while(i <= n) {
            answer += i;
            i = i + 2;
        }
        return answer;
    }
}
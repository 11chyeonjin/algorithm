import java.util.Arrays;

class Solution {
    public int[] solution(String s) {
        int[] alpha = new int[26];
        Arrays.fill(alpha, -1);
        
        int[] answer = new int[s.length()];
        
        int nowIndex;
        for (int i = 0; i < s.length(); i++) {
            nowIndex =  s.charAt(i) - 'a';
                
            if (alpha[nowIndex] == -1) {
                answer[i] = -1;
            } else {
                answer[i] = i - alpha[nowIndex];
            }
            
            alpha[nowIndex] = i;
        }
        
        
        return answer;
    }
}
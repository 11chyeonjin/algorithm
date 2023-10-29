class Solution {
    public String solution(String s) {
        if (s.length() % 2 == 0) {
            String answer = "";
            answer += s.charAt(s.length() / 2 - 1);
            answer += s.charAt(s.length() / 2);
            return answer; 
        } else {
            return Character.toString(s.charAt(s.length() / 2));
        }
    }
}
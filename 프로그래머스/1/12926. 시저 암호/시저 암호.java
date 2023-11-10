class Solution {
    public char func(char c, int n) {
        if (c >= 'a' && c <= 'z') {
            if ((char)(c + n) > 'z')
                return (char)(c + n  - 26);
            else
                return (char)(c + n);
        } else if (c >= 'A' && c <= 'Z') {
            if ((char)(c + n) > 'Z')
                return (char)(c + n - 26);
            else
                return (char)(c + n);
        }
        
        return ' ';
    }
    
    public String solution(String s, int n) {
        String answer = "";
        
        for (int i = 0; i < s.length(); i++) {
            answer += func(s.charAt(i), n);
        }
        
        return answer;
    }
}
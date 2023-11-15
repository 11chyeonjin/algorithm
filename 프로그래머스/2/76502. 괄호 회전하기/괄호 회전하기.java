class Solution {
    public boolean func(String s) {
        int[] tmp = new int[3];
        
        int lastChar = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                tmp[0]++;
                lastChar = 0;
            } else if (s.charAt(i) == ')') {
                tmp[0]--;
                if (lastChar != 0 && lastChar != -1) {
                    return false;
                } else
                    lastChar = -1;
            }
            else if (s.charAt(i) == '[') {
                tmp[1]++;
                lastChar = 1;
            }
            else if (s.charAt(i) == ']') {
                tmp[1]--;
                if (lastChar != 1 && lastChar != -1) {
                    return false;
                } else
                    lastChar = -1;
            }
            else if (s.charAt(i) == '{') {
                tmp[2]++;
                lastChar = 2;
            } 
            else {
                tmp[2]--;
                if (lastChar != 2 && lastChar != -1) {
                    return false;
                } else
                    lastChar = -1;
            }
                
            
            for (int j = 0; j < 3; j++) {
                if (tmp[j] < 0)
                    return false;
            }
        }
        
        for (int j = 0; j < 3; j++) {
            if (tmp[j] != 0)
                return false;
        }
        
        return true;
    }
    
    public int solution(String s) {
        int answer = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (func(s.substring(i) + s.substring(0, i)))
                answer++;
        }
        
        return answer;
    }
}
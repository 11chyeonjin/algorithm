class Solution {
    boolean solution(String s) {
        int tmp = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                tmp++;
            } else {
                tmp--;
            }
            
            if (tmp < 0)
                return false;
        }
        
        if (tmp == 0)
            return true;
        
        return false;
    }
}
import java.util.*;

class Solution {
    public int solution(int[] d, int budget) {
        Arrays.sort(d);
        
        int answer = 0;
        
        int _sum = 0;
        for (int i = 0; i < d.length; i++) {
            _sum += d[i];
            if (_sum <= budget) {
                answer++;
            } else
                break;
        }
        
        return answer;
    }
}
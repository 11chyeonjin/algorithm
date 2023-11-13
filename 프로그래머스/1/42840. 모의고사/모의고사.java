import java.util.*;

class Solution {
    public int func(int[] answer, int[] submit) {
        int cnt = 0;
        
        int submit_i = 0;
        for (int i = 0; i < answer.length; i++) {
            if (answer[i] == submit[submit_i]) {
                cnt++;
            }
            
            submit_i++;
            if (submit_i >= submit.length)
                submit_i = 0;
        }
        
        return cnt;
    }
    
    public int[] solution(int[] answers) {
        int[][] students = {{ 1, 2, 3, 4, 5 }, { 2, 1, 2, 3, 2, 4, 2, 5 }, { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }};
        
        int[] result = new int[3];
        int tmp;
        int maxV = -1;
        for (int i = 0; i < 3; i++) {
            tmp = func(answers, students[i]);
            maxV = Math.max(tmp, maxV);
            result[i] = tmp;
        }
        
        ArrayList<Integer> arrlist = new ArrayList<Integer>();
        for (int i = 0; i < 3; i++) {
            if (result[i] == maxV) {
                arrlist.add(i + 1);
            }
        }
        
        Collections.sort(arrlist);
        int[] rst = new int[arrlist.size()];
        for (int i = 0; i < arrlist.size(); i++) {
            rst[i] = arrlist.get(i);
        }
        
        return rst;
    }
}
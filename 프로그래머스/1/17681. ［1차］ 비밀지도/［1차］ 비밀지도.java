import java.util.*;

class Solution {
    public int[] func(int k, int n) {
        ArrayList<Integer> arrlist = new ArrayList<Integer>();
        
        // 이진수 변환 후 String에 추가 처리
        int tmp = (int)Math.pow(2, n - 1); 
        while (tmp > 0) {
            if (k / tmp == 0) {
                arrlist.add(1); // 텅 빈 공간
            } else {
                arrlist.add(0); // 벽
                k -= tmp;
            }
            tmp /= 2;
        }    
        
        int[] result = new int[arrlist.size()];
        
        for (int i = 0; i < arrlist.size(); i++) {
            result[i] = arrlist.get(i);
        }
        
        return result;
    }

    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] answer = new String[n];
        
        String tmp = "";
        for (int i = 0; i < n; i++) {
            tmp = "";
            int[] arr1tmp = func(arr1[i], n);
            int[] arr2tmp = func(arr2[i], n);
            for (int j = 0; j < n; j++) {
                if ((arr1tmp[j] * arr2tmp[j]) == 1) {
                    tmp += " ";
                } else
                    tmp += "#";
            }
            answer[i] = tmp;
        }
        
        return answer;
    }
}
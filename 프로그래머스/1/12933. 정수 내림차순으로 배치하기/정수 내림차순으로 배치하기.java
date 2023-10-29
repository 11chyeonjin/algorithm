import java.util.*;

class Solution {
    public long func(int n) {
        long result = 1;
        for (int i = 0; i < n; i++) {
            result *= 10;
        }
        return result;
    }
    
    public long solution(long n) {
        String str = Long.toString(n);
        
        int [] sol = new int[str.length()];
        for (int i = 0; i < str.length(); i++) {
            sol[i] = str.charAt(i) - '0';
        }
        
        Integer[] arr = Arrays.stream(sol).boxed().toArray(Integer[]::new);
        
        Arrays.sort(arr, Collections.reverseOrder());
        System.out.println(Arrays.toString(arr));
        
        long answer = 0;
        for (int i = 0; i < arr.length; i++) {
            answer += arr[i] * func(arr.length - i - 1);
        }
        
        return answer;
    }
}
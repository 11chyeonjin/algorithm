import java.util.*;

class Solution {
    public static int cnt = 0;
    
    public static void combination(int[] arr, boolean[] visited, int start, int n, int r) {
        if (r == 0) {
            int _sum = 0;
            for (int i = 0; i < n; i++) {
                if (visited[i])
                    _sum += arr[i];
            }
            if (_sum == 0) {
                cnt++;
            }
            return;
        }
        
        for (int i = start; i < n; i++) {
            visited[i] = true;
            combination(arr, visited, i + 1, n, r - 1);
            visited[i] = false;
        }
    }
    
    public int solution(int[] number) {
        boolean[] visited = new boolean[13];
        
        combination(number, visited, 0, number.length, 3);
        
        return cnt;
    }
}
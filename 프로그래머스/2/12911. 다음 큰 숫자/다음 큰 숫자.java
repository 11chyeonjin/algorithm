class Solution {
    public int func(int num) {
        /**
            n : 계산용 / 변수 크기에 따른 이진수 임시 변수
            result : 1의 갯수 변수
        */
        int n = 1;
        int result = 0;
        
        while(n <= num) {
            n *= 2;
        }
        
        // 이하 1의 갯수 계산
        while(n > 0) {
            if (n <= num) {
                num -= n;
                n /= 2;
                result++;
            } else {
                n /= 2;
            }
        }
        
        return result;
    }
    
    public int solution(int n) {
        int target = func(n);
        
        int m = n + 1;
        while(true) {
            if (func(m) == target) {
                break;
            }
            m++;
        }
        
        return m;
    }
}
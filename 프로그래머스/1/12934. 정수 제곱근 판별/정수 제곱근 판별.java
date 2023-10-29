class Solution {
    public long solution(long n) {
        double d = Math.sqrt(n);
        
        if (d == (long) d) { // 정수라면
            return ((long)d + 1) * ((long)d + 1);
        } else {
            return -1;
        }
    }
}
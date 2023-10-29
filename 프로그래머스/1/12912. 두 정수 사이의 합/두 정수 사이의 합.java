class Solution {
    public long solution(int a, int b) {
        int minV = Math.min(a, b);
        int maxV = Math.max(a, b);
        
        return ((long)a + b) * (maxV - minV + 1) / 2;
    }
}
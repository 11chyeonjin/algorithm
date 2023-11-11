class Solution {
    public long solution(int price, int money, int count) {
        long answer = (price + (long)price * count) * count / 2 - money;
        
        if (answer < 0)
            answer = 0L;

        return answer;
    }
}
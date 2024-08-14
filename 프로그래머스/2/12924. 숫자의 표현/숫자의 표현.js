function solution(n) {
    let answer = 1; // n = n의 경우
    
    let _front = 1;
    let _back = 1;
    let curSum = 1;
    
    while(_back <= n / 2 + 1 && _front <= n / 2) {
        if (curSum > n) {
            curSum -= _front++;
        } else if (curSum < n) {
            curSum += ++_back;
        } else {
            curSum -= _front++;
            answer++;
        }
    }
    
    return answer;
}
function solution(n) {
    let answer = "";
    
    const arr = ["4", "1", "2"];
    
    while (n > 0) {
        const r = n % 3;
        n = Math.floor((n - 1) / 3);
        answer = arr[r] + answer;
    }
    
    return answer;
}
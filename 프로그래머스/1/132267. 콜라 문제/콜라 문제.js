function solution(a, b, n) {
    let answer = 0;
    
    while(n >= a) {
        const curP = Math.floor(n / a);
        n = n - curP * a + curP * b;
        answer += curP * b;
    }
    
    return answer;
}
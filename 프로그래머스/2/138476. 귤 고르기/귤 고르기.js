function solution(k, tangerine) {
    const map = new Map();
    
    for (const t of tangerine) {
        map.set(t, (map.get(t) ?? 0) + 1);
    }
    
    const arr = [...map].sort((a, b) => b[1] - a[1]);
    
    let answer = 0;
    let cur = 0;
    
    for (const [t, num] of arr) {
        cur += num;
        answer++;
        
        if (cur >= k) {
            return answer;
        }
    }
    
    return answer;
}
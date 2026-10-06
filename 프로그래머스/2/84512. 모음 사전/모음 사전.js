function solution(word) {
    const arr = ['A', 'E', 'I', 'O', 'U'];
    
    const s = [''];
    let answer = -1;
    
    while(s.length > 0) {
        const cStr = s.pop();
        answer++;
        
        if (cStr === word) {
            return answer;
        }
        
        if (cStr.length === 5) {
            continue;
        }
        
        for (let i = arr.length - 1; i >= 0; i--) {
            s.push(cStr + arr[i]);
        }
    }
    
    return answer;
}
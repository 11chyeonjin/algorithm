function solution(s) {
    // (문자 무관) 인덱스 한 개를 기준으로 dp 하면서 늘리기
    // (문자가 동일한) 인덱스 두 개를 기준으로 dp 하면서 늘리기
    
    if (s.length === 0) {
        return 0;
    }
    
    let answer = 1;
    
    for (let i = 1; i < s.length - 1; i++) {
        // 인덱스 한 개 기준
        
        let left = i - 1;
        let right = i + 1;
        
        let rst = 1;
        
        while(0 <= left && right < s.length) {
            if (s[left] !== s[right]) {
                break;
            }
            
            rst += 2;
            left--; right++;
        }
        
        answer = Math.max(answer, rst);
    }
    
    for (let i = 0; i < s.length - 1; i++) {
        // 인덱스 두 개 기준 (문자 동일 확인한 후 진행)
        let left = i
        let right = i + 1;
        
        let rst = 0;
        
        while(0 <= left && right < s.length) {
            if (s[left] !== s[right]) {
                break;
            }
            
            rst += 2;
            left--; right++;
        }
        
        answer = Math.max(answer, rst);
    }
    
    return answer;
}
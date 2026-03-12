function solution(signals) {
    let limit = 1;
    
    for (const [g, y, r] of signals) {
        limit *= g + y + r;
    }
    
    const setArr = Array.from({ length: signals.length }, () => new Set());
    
    for (let i = 0; i < signals.length; i++) {
        const [g, y, r] = signals[i];
        
        let cur = g;
        
        while(cur <= limit) {
            for (let j = 1; j <= y; j++) {
                setArr[i].add(cur + j);
            }
            
            cur += g + y + r;
        }
    }
    
    for (let i = 2; i <= limit; i++) {
        let flag = true;
        
        for (const set of setArr) {
            if (!set.has(i)) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            return i;
        }
    }
    
    return -1;
}
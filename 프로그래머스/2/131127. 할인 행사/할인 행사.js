function solution(want, number, discount) {
    let answer = 0;
    const user = new Map();
    
    for (let i = 0; i < want.length; i++) {
        user.set(want[i], number[i]);
    }
    
    const mart = new Map();
    for (let i = 0; i < Math.min(10, discount.length); i++) {
        mart.has(discount[i]) ? mart.set(discount[i], mart.get(discount[i]) + 1) : mart.set(discount[i], 1);
    }
    
    function check() {
        for (const [p, c] of user) {
            if (!mart.has(p)) {
                return false;
            }
            
            if (mart.get(p) < c) {
                return false;
            }
        }
        
        return true;
    }
    
    if (check()) {
        answer++;
    }
    
    for (let i = 1; i <= discount.length - 10; i++) {
        const oo = i - 1;
        const ii = i + 9;
        
        mart.set(discount[oo], mart.get(discount[oo]) - 1);
        
        mart.has(discount[ii]) ? mart.set(discount[ii], mart.get(discount[ii]) + 1) : mart.set(discount[ii], 1);
        
        if (check()) {
            answer++;
        }
    }
    
    return answer;
}
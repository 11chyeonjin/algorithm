function solution(order) {
    let answer = 0;
    
    const s = [];
    
    function check_s(curTarget) {
        if (s.length === 0) {
            return false;
        }
        
        if (s[s.length - 1] === curTarget) {
            answer++;
            s.pop();
            return true;
        }
    }
    
    for (let i = 1; i <= order.length; i++) {
        while(check_s(order[answer])) {
            continue;
        }
        
        if (i === order[answer]) {
            answer++;
        } else {
            s.push(i);
        }
    }
    
    while(check_s(order[answer])) {
        continue;
    }
    
    return answer;
}
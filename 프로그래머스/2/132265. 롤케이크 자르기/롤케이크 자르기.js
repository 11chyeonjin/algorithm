function solution(topping) {
    let answer = 0;
    
    const left = new Set();
    left.add(topping[0]);
    
    const right = new Map();
    for (let i = 1; i < topping.length; i++) {
        right.set(topping[i], (right.get(topping[i]) ?? 0) + 1);
    }
    
    for (let i = 1; i < topping.length - 1; i++) {
        if (left.size === right.size) {
            answer++;
        }
        
        left.add(topping[i]);
        
        if (right.get(topping[i]) === 1) {
            right.delete(topping[i]);
        } else {
            right.set(topping[i], right.get(topping[i]) - 1);
        }
    }
    
    return answer;
}
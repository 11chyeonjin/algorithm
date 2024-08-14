function solution(ingredient) {
    let _stack = [];
    
    let answer = 0;
    
    for (let i = 0; i < ingredient.length; i++) {
        _stack.push(ingredient[i]);
        
        if (_stack.length >= 4) {
            let lastFour = _stack.slice(-4);
            if (lastFour.join('') === '1231') {
                _stack.splice(-4);
                answer++;
            }
        }
    }
    
    return answer;
}
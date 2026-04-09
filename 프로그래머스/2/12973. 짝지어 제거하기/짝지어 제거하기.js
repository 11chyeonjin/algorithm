function solution(s) {
    const stack = [];
    
    for (const c of s) {
        if (stack.length > 0 && stack[stack.length - 1] === c) {
            stack.pop();
        } else{
            stack.push(c);
        }
    }
    
    if (stack.length === 0) {
        return 1;
    } else {
        return 0;
    }
}
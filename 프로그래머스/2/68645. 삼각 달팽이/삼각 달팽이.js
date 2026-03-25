function solution(n) {
    const arr = Array.from({ length: n }, () => []);
    
    function go(start, end, cur) {
        const curSize = end - start + 1;
        
        for (let i = start; i < end; i++) {
            arr[i].push(cur++);
        }
        for (let i = 0; i < curSize; i++) {
            arr[end].push(cur++);
        }
        
        if (start + 2 <= end - 1) {
            go(start + 2, end - 1, cur + curSize - 2);
        }
        
        for (let i = end - 1; i > start; i--) {
            arr[i].push(cur++);
        }
    }
    
    go(0, n - 1, 1);
    
    return arr.flat();
}
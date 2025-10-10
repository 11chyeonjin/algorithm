function solution(N, number) {
    const arr = Array.from({ length: 9 }, () => new Set());
    
    arr[1].add(N);
    
    if (N === number) {
        return 1;
    }
    
    for (let i = 2; i <= 8; i++) {
        let str = '';
        for (let j = 0; j < i; j++) {
            str += N;
        }
        arr[i].add(Number(str));
        
        for (let a = 1; a < i; a++) {
            for (const aa of arr[a]) {
                for (const bb of arr[i - a]) {
                    arr[i].add(aa + bb);
                    arr[i].add(aa - bb);
                    arr[i].add(bb - aa);
                    arr[i].add(aa * bb);
                    
                    if (bb !== 0) {
                        arr[i].add(Math.floor(aa / bb));
                    }
                    
                    if (aa !== 0) {
                        arr[i].add(Math.floor(bb / aa));
                    }
                }
            }
        }
        
        if (arr[i].has(number)) {
            return i;
        }
    }
    
    return -1;
}
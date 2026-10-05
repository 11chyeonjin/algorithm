function solution(sequence) {
    let sumA = 0;
    let sumB = 0;
    
    let maxV = -Infinity;
    
    for (let i = 0; i < sequence.length; i++) {
        let curA = sequence[i] * (i % 2 ? 1 : -1);
        let curB = sequence[i] * (i % 2 ? -1 : 1);
        
        sumA = Math.max(curA, sumA + curA);
        sumB = Math.max(curB, sumB + curB);
        
        maxV = Math.max(maxV, sumA, sumB);
    }
    
    return maxV;
}
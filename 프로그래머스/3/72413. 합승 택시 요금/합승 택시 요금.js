function solution(n, s, a, b, fares) {
    // 노드 수 n
        // 출발 노드 s (인덱스 1~)
        // 도착지점 a, b
    // [c, d, f]
        // f 요금

    const fw = Array.from({ length: n + 1 }, () => Array.from({ length: n + 1 }, () => Infinity));
    
    fares.forEach(([c, d, f]) => {
        fw[c][d] = f;
        fw[d][c] = f;
    })
    
    for (let i = 1; i < n + 1; i++) {
        fw[i][i] = 0;
    }
    
    for (let k = 1; k < n + 1; k++) {
        for (let i = 1; i < n + 1; i++) {
            for (let j = 1; j < n + 1; j++) {
                fw[i][j] = Math.min(fw[i][j], fw[i][k] + fw[k][j]);
            }
        }
    }
    
    let answer = Infinity;
    
    for (let i = 1; i < n + 1; i++) {
        let tmp = 0;
        tmp += fw[s][i] + fw[i][a] + fw[i][b];
        
        answer = Math.min(answer, tmp);
    }
    
    return answer;
}
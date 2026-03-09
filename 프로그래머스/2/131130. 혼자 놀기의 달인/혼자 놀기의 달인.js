function solution(cards) {
    // 모든 사이클을 찾고, 가장 큰 두 개의 사이클의 원소 수의 곱한 답을 출력
    
    cards.unshift(0);
    
    let num = 1;
    const cycle = Array.from({ length: cards.length }, () => []);
    
    for (let i = 1; i < cards.length; i++) {
        if (cycle[i].length !== 0) {
            continue;
        }
        
        cycle[i].push(i);
        
        let next = cards[i];
        while(cycle[next].length === 0) {
            cycle[next] = cycle[i];
            cycle[i].push(next);
            next = cards[next];
        }
    }
    
    const sortArr = [...new Set(cycle)].map(arr => arr.length).sort((a, b) => b - a);
    
    return sortArr[0] * sortArr[1];
}
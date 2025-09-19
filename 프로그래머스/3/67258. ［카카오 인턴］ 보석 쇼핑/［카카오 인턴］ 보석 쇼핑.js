function solution(gems) {
    const answer = [];
    let min_size = Infinity;
    
    const set = new Set(gems);
    const map = new Map(); // "gem", 1
    // 0 일때는 map에서 제외
    
    let front = 0;
    
    for (let back = 0; back < gems.length; back++) {
        const back_gem = gems[back];
        
        map.set(back_gem, map.has(back_gem) ? map.get(back_gem) + 1 : 1);
        
        while(map.get(gems[front]) > 1) {
            map.set(gems[front], map.get(gems[front]) - 1);
            front++;
        }
        
        if (map.size === set.size && min_size > back - front + 1) {
            min_size = back - front + 1;
            answer[0] = front + 1;
            answer[1] = back + 1;
        }
    }
    
    return answer;
}
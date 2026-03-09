function solution(n, roads, sources, destination) {
    const graph = Array.from({ length: n + 1 }, () => []);
    
    for (const [from, to] of roads) {
        graph[from].push(to);
        graph[to].push(from);
    }
    
    const cost = Array.from({ length: n + 1 }, () => Infinity);
    cost[destination] = 0;
    
    const q = [[destination, 0]];
    let qi = 0;
    
    while(qi < q.length) {
        const [cur, curTime] = q[qi++];
        
        for (let i = 0; i < graph[cur].length; i++) {
            const next = graph[cur][i];
            const tmpTime = curTime + 1;
            
            if (cost[next] > tmpTime) {
                cost[next] = tmpTime;
                q.push([next, tmpTime]);
            }
        }
    }
    
    const rst = [];
    
    for (const cur of sources) {
        if (cost[cur] === Infinity) {
            rst.push(-1);
        } else {
            rst.push(cost[cur]);
        }
    }
    
    return rst;
}
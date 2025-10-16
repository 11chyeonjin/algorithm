function solution(a, edges) {
    let rst = 0;
    for (let e of a) {
        rst += e;
    }
    if (rst !== 0) {
        return -1;
    }
    
    const graph = Array.from({ length: a.length }, () => []);
    
    for (const [from, to] of edges) {
        graph[from].push(to);
        graph[to].push(from);
    }
    
    const edge = graph.map((node) => node.length);
    
    const q = [];
    let qi = 0;
    
    for (let i = 0; i < a.length; i++) {
        if (edge[i] === 1) {
            q.push(i);
        }
    }
    
    let answer = BigInt(0);

    while (qi < q.length) {
        const cur = q[qi++];
        edge[cur]--;

        for (const next of graph[cur]) {
            if (edge[next] === 0) {
                continue;
            }
                
            answer += BigInt(Math.abs(a[cur]));
            a[next] += a[cur];
            a[cur] = 0;
            edge[next]--;
            
            if (edge[next] === 1) {
                q.push(next);
            }
        }
    }

    return Number(answer);
}
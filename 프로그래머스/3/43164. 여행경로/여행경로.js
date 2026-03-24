function solution(tickets) {
    const set = new Set(tickets.flat());
    
    const graph = new Map();
    
    for (const s of set) {
        graph.set(s, []);
    }
    
    for (const [from, to] of tickets) {
        graph.get(from).push([to, false]);
    }
    
    for (const arr of graph) {
        arr[1].sort((a, b) => a[0].localeCompare(b[0]));
    }
    
    const result = [];
    const arr = [];
    
    function dfs(cur, depth) {
        arr[depth] = cur;
        
        if (depth === tickets.length) {
            result.push(arr.slice());
            return;
        }
        
        const curRouteArr = graph.get(cur);
        
        for (let i = 0; i < curRouteArr.length; i++) {
            const [next, nextVisited] = curRouteArr[i];
            
            if (!nextVisited) {
                curRouteArr[i][1] = true;
                dfs(next, depth + 1);
                curRouteArr[i][1] = false;
            }
        }
    }
    
    dfs("ICN", 0);
    
    return result[0];
}
class PriorityQueue {
    constructor() {
        this.heap = [];
    }
    
    swap(a, b) {
        [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
    }
    
    isEmpty() {
        return this.heap.length === 0;
    }
    
    push(e) {
        this.heap.push(e);
        this.up();
    }
    
    pop() {
        if (this.isEmpty()) {
            return null;
        }
        
        if (this.heap.length === 1) {
            return this.heap.pop();
        }
        
        const root = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.down();
        return root;
    }
    
    up() {
        let c = this.heap.length - 1;
        
        while(c > 0) {
            const p = Math.floor((c - 1) / 2);
            
            if (this.heap[p][1] <= this.heap[c][1]) {
                break;
            }
            
            this.swap(c, p);
            c = p;
        }
    }
    
    down() {
        let p = 0;
        const ll = this.heap.length;
        
        while(true) {
            let lc = p * 2 + 1;
            let rc = p * 2 + 2;
            let pp = p;
            
            if (lc < ll && this.heap[lc][1] < this.heap[pp][1]) {
                pp = lc;
            }
            
            if (rc < ll && this.heap[rc][1] < this.heap[pp][1]) {
                pp = rc;
            }
            
            if (p === pp) {
                break;
            }
            
            this.swap(p, pp);
            p = pp;
        }
    }
}

function solution(n, edge) {
    const graph = Array.from({ length: n + 1 }, () => []);
    
    for (const [f, t] of edge) {
        graph[f].push(t);
        graph[t].push(f);
    }
    
    const cost = Array.from({ length: n + 1 }, () => Infinity);
    const visited = Array.from({ length: n + 1 }, () => false);
    
    const pq = new PriorityQueue();
    pq.push([1, 0]);
    cost[1] = 0;
    
    while(!pq.isEmpty()) {
        const [curNode, curCost] = pq.pop();
        
        if (visited[curNode]) {
            continue;
        }
        
        visited[curNode] = true;
        
        for (const next of graph[curNode]) {
            if (cost[next] > curCost + 1) {
                pq.push([next, curCost + 1]);
                cost[next] = curCost + 1;
            }
        }
    }
    
    let answer = 0;
    
    const mCost = Math.max(...cost.slice(1));
    
    for (const c of cost) {
        if (c === mCost) {
            answer++;
        }
    }
    
    return answer;
}
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
            let p = Math.floor((c - 1) / 2);
            
            if (this.heap[p][2] <= this.heap[c][2]) {
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
            
            if (lc < ll && this.heap[lc][2] < this.heap[pp][2]) {
                pp = lc;
            }
            
            if (rc < ll && this.heap[rc][2] < this.heap[pp][2]) {
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

function solution(land, height) {
    const N = land.length;
    
    const dy = [0, 0, 1, -1];
    const dx = [1, -1, 0, 0];
    
    const visited = Array.from({ length: N }, () => Array.from({ length: N }, () => false));
    let answer = 0;
    
    const pq = new PriorityQueue();
    pq.push([0, 0, 0]);
    
    while(!pq.isEmpty()) {
        const [y, x, cost] = pq.pop();
        
        if (visited[y][x]) {
            continue;
        }

        visited[y][x] = true;
        answer += cost;
        
        for (let i = 0; i < 4; i++) {
            const nY = y + dy[i];
            const nX = x + dx[i];
            
            if (0 <= nY && nY < N && 0 <= nX && nX < N) {
                if (!visited[nY][nX]) {
                    let nCost = Math.abs(land[nY][nX] - land[y][x]);
                    if (nCost <= height) {
                        nCost = 0;
                    }
                    pq.push([nY, nX, nCost]);
                }
            }
        }
    }
    
    return answer;
}
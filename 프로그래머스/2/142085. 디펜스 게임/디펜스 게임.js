class PriorityQueue {
    constructor() {
        this.heap = [];
    }
    
    swap(a, b) {
        [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
    }
    
    push(e) {
        this.heap.push(e);
        this.up();
    }
    
    pop() {
        if (this.heap.length === 0) {
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
            
            if (this.heap[p] <= this.heap[c]) {
                break;
            }
            
            this.swap(c, p);
            c = p;
        }
    }
    
    down() {
        let p = 0;
        const limit = this.heap.length;
        
        while(true) {
            const lc = p * 2 + 1;
            const rc = p * 2 + 2;
            let pp = p;
            
            if (lc < limit && this.heap[lc] < this.heap[pp]) {
                pp = lc;
            }
            
            if (rc < limit && this.heap[rc] < this.heap[pp]) {
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

function solution(n, k, enemy) {
    const pq = new PriorityQueue();
    
    if (enemy.length <= k) {
        return enemy.length;
    }
    
    // 무적권을 임시로 다 썼다고 가정
    for (let i = 0; i < k; i++) {
        pq.push(enemy[i]);
    }
    
    for (let i = k; i < enemy.length; i++) {
        pq.push(enemy[i]);
        const minEnemy = pq.pop();
        
        n -= minEnemy;
        
        if (n < 0) {
            return i;
        }
    }
    
    return enemy.length;
}
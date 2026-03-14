class PriorityQueue {
    constructor(arr = []) {
        this.heap = [];
        
        for (const a of arr) {
            this.push(a);
        }
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
        
        while (c > 0) {
            let p = Math.floor((c - 1) / 2);
            
            if (this.heap[p] >= this.heap[c]) {
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
            
            if (lc < limit && this.heap[lc] > this.heap[pp]) {
                pp = lc;
            }
            
            if (rc < limit && this.heap[rc] > this.heap[pp]) {
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

function solution(n, works) {
    // works에서 제일 큰 값을 찾아서 줄이는 식의 연산 필요
    
    const pq = new PriorityQueue(works);
    
    while(n-- > 0 && pq.heap.length > 0) {
        const cur = pq.pop();
        
        if (cur > 1) {
            pq.push(cur - 1);
        }
    }
    
    let answer = 0;
    for (const e of pq.heap) {
        answer += e ** 2;
    }
    
    return answer;
}
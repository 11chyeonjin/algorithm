class PriorityQueue {
    constructor() {
        this.heap = [];
    }
    
    size() {
        return this.heap.length;
    }
    
    compare(a, b) {
        const [aI, aS, aL] = a;
        const [bI, bS, bL] = b;
        
        if (aL !== bL) {
            return aL < bL
        }
        
        if (aS !== bS) {
            return aS < bS;
        }
        
        return aI < bI;
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
            
            if (this.compare(this.heap[p], this.heap[c])) {
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
            
            if (lc < limit && this.compare(this.heap[lc], this.heap[pp])) {
                pp = lc;
            }
            
            if (rc < limit && this.compare(this.heap[rc], this.heap[pp])) {
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

function solution(jobs) {
    jobs.sort((a, b) => a[0] - b[0]);
    
    const pq = new PriorityQueue();
    
    let taskI = 0;
    let curTime = 0;
    let rstSum = 0;
    
    while(taskI < jobs.length || pq.size() > 0) {
        // 요청된 작업 큐에 삽입       
        while(taskI < jobs.length) {
            const [s, l] = jobs[taskI];

            if (curTime >= s) {
                pq.push([taskI++, s, l]);
            } else {
                break;
            }
        }
        
        if (pq.size() === 0) {
            curTime++;
            continue;
        }
        
        const [curI, curS, curL] = pq.pop();
        curTime += curL;
        rstSum += curTime - curS;
    }
    
    return Math.floor(rstSum / jobs.length);
}
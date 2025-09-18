class PriorityQueue {
    constructor(compare = (a, b) => a - b) {
        this.heap = [];
        this.compare = compare;
    }
    
    isEmpty() {
        return this.heap.length === 0;
    }
    
    setEmpty() {
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
            let p = Math.floor((c - 1) / 2);
            
            if (this.compare(this.heap[p], this.heap[c]) <= 0) {
                break;
            }
            
            this.swap(c, p);
            c = p;
        }
    }
    
    down() {
        let p = 0;
        let limit = this.heap.length;
        
        while(true) {
            let lc = 2 * p + 1;
            let rc = 2 * p + 2;
            let pp = p;
            
            if (lc < limit && this.compare(this.heap[lc], this.heap[pp]) < 0) {
                pp = lc;
            }
            
            if (rc < limit && this.compare(this.heap[rc], this.heap[pp]) < 0) {
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

function solution(operations) {
    const minQ = new PriorityQueue();
    const maxQ = new PriorityQueue((a, b) => b - a);
    
    const map = new Map();
    
    for (const oper of operations) {
        let [operChar, operNum] = oper.split(' ');
        operNum = Number(operNum);
        
        if (operChar === 'I') {
            minQ.push(operNum);
            maxQ.push(operNum);
            map.set(operNum, map.get(operNum) + 1 || 1);
        }
        
        if (operChar === 'D' && operNum === 1 && !maxQ.isEmpty()) {
            let max_top = maxQ.pop();
            while(!maxQ.isEmpty() && !map.has(max_top)) {
                max_top = maxQ.pop();
            }
            
            if (map.get(max_top) === 1) {
                map.delete(max_top);
            } else {
                map.set(max_top, map.get(max_top) - 1);
            }
        }
        
        if (operChar === 'D' && operNum === -1 && !minQ.isEmpty()) {
            let min_top = minQ.pop();
            while(!minQ.isEmpty() && !map.has(min_top)) {
                min_top = minQ.pop();
            }
            
            if (map.get(min_top) === 1) {
                map.delete(min_top);
            } else {
                map.set(min_top, map.get(min_top) - 1);
            }
        }
    }
    
    console.log(map);
    
    const answer = [0, 0];
    
    if (!maxQ.isEmpty()) {
        let max_top = maxQ.pop();
        while(!maxQ.isEmpty() && !map.has(max_top)) {
            max_top = maxQ.pop();
        }

        
        if (map.has(max_top)) {
            answer[0] = max_top;
        }
    }
    
    if (!minQ.isEmpty()) {
        let min_top = minQ.pop();
        while(!minQ.isEmpty() && !map.has(min_top)) {
            min_top = minQ.pop();
        }
        
        if (map.has(min_top)) {
            answer[1] = min_top;
        }
    }
    
    return answer;
}
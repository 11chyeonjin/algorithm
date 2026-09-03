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
    
    front() {
        return this.heap[0];
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
            
            if (this.heap[p] <= this.heap[c]) {
                break;
            }
            
            this.swap(c, p);
            c = p;
        }
    }
    
    down() {
        let p = 0; const ll = this.heap.length;
        
        while(true) {
            const lc = p * 2 + 1; const rc = p * 2 + 2;
            let pp = p;
            
            if (lc < ll && this.heap[lc] < this.heap[pp]) {
                pp = lc;
            }
            
            if (rc < ll && this.heap[rc] < this.heap[pp]) {
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

function solution(k, n, reqs) {
    const reqArr = Array.from({ length: k + 1 }, () => []);
        
    for (const [_at, _hour, _type] of reqs) {
        reqArr[_type].push([_at, _hour]);
    }
    
    const combArr = [];
    const combR = [];
    
    function comb(p, r) {
        if (p === k - 1) {
            combR[k - 1] = r;
            combArr.push(combR.map(e => e + 1));
            return;
        }
        
        for (let i = 0; i <= r; i++) {
            combR[p] = i;
            comb(p + 1, r - i);
        }
    }
    
    function simul(arr) { 
        const rst = Array.from({ length: k + 1 }, () => new PriorityQueue());
        
        let target = 0;
        
        for (let i = 0; i < arr.length; i++) {
            for (let j = 0; j < arr[i]; j++) {
                rst[i + 1].push(0);
            }
        }
        
        for (let i = 1; i <= k; i++) {
            for (let j = 0; j < reqArr[i].length; j++) {
                const [_at, _hour] = reqArr[i][j];
                
                if (rst[i].front() <= _at) {
                    rst[i].pop();
                    rst[i].push(_at + _hour);
                } else {
                    target += rst[i].front() - _at;
                    rst[i].push(rst[i].pop() + _hour);
                }
            }
        }
        
        return target;
    }
    
    let answer = Infinity;
    
    comb(0, n - k);
    combArr.forEach(e => {
        answer = Math.min(answer, simul(e));
    })
    
    return answer;
}
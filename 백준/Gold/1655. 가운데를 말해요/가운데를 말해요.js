class PriorityQueueMin {
  constructor() {
    this.heap = [];
  }

  swap(a, b) {
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
  }
  
  size() {
    return this.heap.length;
  }

  top() {
    return this.heap[0];
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
      
      if (this.heap[p] <= this.heap[c]) {
        break;
      }

      this.swap(c, p);
      c = p;
    }
  }

  down() {
    let p = 0;
    const lengthLimit = this.heap.length;
    
    while(true) {
      let lc = 2 * p + 1;
      let rc = 2 * p + 2;
      let pp = p;
      
      if (lc < lengthLimit && this.heap[lc] < this.heap[pp]) {
        pp = lc;
      }

      if (rc < lengthLimit && this.heap[rc] < this.heap[pp]) {
        pp = rc;
      }

      if (pp === p) {
        break;
      }

      this.swap(p, pp);
      p = pp;
    }
  }
}

class PriorityQueueMax {
  constructor() {
    this.heap = [];
  }

  swap(a, b) {
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
  }

  top() {
    return this.heap[0];
  }
  
  size() {
    return this.heap.length;
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
      
      if (this.heap[p] >= this.heap[c]) {
        break;
      }

      this.swap(c, p);
      c = p;
    }
  }

  down() {
    let p = 0;
    const lengthLimit = this.heap.length;
    
    while(true) {
      let lc = 2 * p + 1;
      let rc = 2 * p + 2;
      let pp = p;
      
      if (lc < lengthLimit && this.heap[lc] > this.heap[pp]) {
        pp = lc;
      }

      if (rc < lengthLimit && this.heap[rc] > this.heap[pp]) {
        pp = rc;
      }

      if (pp === p) {
        break;
      }

      this.swap(p, pp);
      p = pp;
    }
  }
}

const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const rst = solution(Number(input[0]), input.slice(1).map(e => +e));
  console.log(rst.join('\n'));
})

function solution(N, arr) {
  const pqMax = new PriorityQueueMax();
  const pqMin = new PriorityQueueMin();

  // pqMax - MidValue - pqMin

  const rst = [];
  
  arr.forEach((e, i) => {
    if (i % 2 === 0) {
      pqMax.push(e);
    } else {
      pqMin.push(e);
    }

    if (!pqMin.isEmpty()) {
      while (pqMax.top() > pqMin.top()) {
        const tmp1 = pqMax.pop();
        const tmp2 = pqMin.pop();
        pqMax.push(tmp2);
        pqMin.push(tmp1);
      }
    }

    rst.push(pqMax.top());
  });

  return rst;
}
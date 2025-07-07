const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const rst = solution(input.slice(1).map(Number));
  console.log(rst);
  process.exit();
});

class PQ {
  constructor() {
    this.heap = [];
  }

  swap(a, b) {
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
  }

  isEmpty() {
    return this.heap.length === 0;
  }

  size() {
    return this.heap.length;
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
    const limit = this.heap.length;

    while(true) {
      let lc = p * 2 + 1;
      let rc = p * 2 + 2;
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

function solution(arr) {
  const pq = new PQ();
  arr.forEach(e => {
    pq.push(e);
  });

  let answer = 0;

  while(pq.size() > 1) {
    const tmp = pq.pop() + pq.pop();
    answer += tmp;
    pq.push(tmp);
  }

  return answer;
}
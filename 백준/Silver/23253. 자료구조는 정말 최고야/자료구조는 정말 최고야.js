const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  console.log(solution(input[0], input.slice(1)));
  process.exit();
});

class PriorityQueue {
  constructor() {
    this.heap = [];
  }

  isEmpty() {
    return this.heap.length === 0;
  }

  swap(a, b) {
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
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

      if (this.heap[p][this.heap[p].length - 1] <= this.heap[c][this.heap[c].length - 1]) {
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
      let lc = 2 * p + 1;
      let rc = 2 * p + 2;
      let pp = p;

      if (lc < limit && this.heap[lc][this.heap[lc].length - 1] < this.heap[pp][this.heap[pp].length - 1]) {
        pp = lc;
      }

      if (rc < limit && this.heap[rc][this.heap[rc].length - 1] < this.heap[pp][this.heap[pp].length - 1]) {
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

function solution([N, M], arr) {

  const pq = new PriorityQueue();

  for (let i = 0; i < arr.length; i++) {
    if (i % 2) {
      pq.push(arr[i]);
    }
  }

  let cur = 0;

  while(!pq.isEmpty()) {
    const fArray = pq.pop();
    
    const fAf = fArray.pop();
    
    if (fAf === cur + 1) {
      cur++;
      if (fArray.length !== 0) {
        pq.push(fArray);
      }
    } else {
      break;
    }
  }

  return cur === N ? "Yes" : "No";
}
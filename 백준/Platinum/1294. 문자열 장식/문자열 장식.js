const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const ans = solution(Number(input[0]), input.slice(1));
  console.log(ans);
  process.exit();
});

class PriorityQueue {
  constructor() {
    this.heap = [];
    this.compare = (arr1, arr2) => {
      const minL = Math.min(arr1.length, arr2.length);
      for (let i = 0; i < minL; i++) {
        if (arr1[i] < arr2[i]) {
          return -1;
        } else if (arr1[i] > arr2[i]) {
          return 1;
        }
      }

      if (arr1.length > arr2.length) {
        return -1; // 앞선 비교에서 동일하다면, 짧은 것을 먼저 소모
      } else if (arr1.length < arr2.length) {
        return 1;
      } else {
        return 0;
      }
    }
  }

  swap(a, b) {
    [this.heap[a], this.heap[b]] = [this.heap[b], this.heap[a]];
  }

  empty() {
    return this.heap.length === 0;
  }

  push(e) {
    this.heap.push(e);
    this.up();
  }

  pop() {
    if (this.empty()) {
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

      if (this.compare(this.heap[p], this.heap[c]) <= 0) {
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

function solution(N, arr) {
  const pq = new PriorityQueue();
  arr.forEach(e => {
    pq.push(e);
  });

  const answerArr = [];

  while (!pq.empty()) {
    const curStrArr = pq.pop();
    answerArr.push(curStrArr[0]);
    
    if (curStrArr.length > 1) {
      pq.push(curStrArr.slice(1));
    }
  }

  return answerArr.join('');
}


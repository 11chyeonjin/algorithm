const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  console.log(solution(input[0][0], input[1], input[2], input.slice(3)));
  process.exit();
});

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
      const p = Math.floor((c - 1) / 2);

      if (this.heap[p][1] <= this.heap[c][1]) {
        break;
      }

      this.swap(c, p);
      c = p;
    }
  }

  down() {
    let p = 0;
    const limit = this.heap.length;

    while (true) {
      const lc = p * 2 + 1;
      const rc = p * 2 + 2;
      let pp = p;

      if (lc < limit && this.heap[lc][1] < this.heap[pp][1]) {
        pp = lc;
      }

      if (rc < limit && this.heap[rc][1] < this.heap[pp][1]) {
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

function toStr(arr) {
  return arr.join(",");
}

function toArr(str) {
  return str.split(",").map(Number);
}

function check(arr) {
  for (let i = 0; i < arr.length - 1; i++) {
    if (arr[i] > arr[i + 1]) {
      return false;
    }
  }

  return true;
}

function solution(N, A, M, oper) {
  const pq = new PriorityQueue();
  const map = new Map();

  let answer = Infinity;

  pq.push([toStr(A), 0]);
  map.set(toStr(A), 0);

  while (!pq.isEmpty()) {
    const [curStr, cost] = pq.pop();

    const curArr = toArr(curStr);

    if (check(curArr)) {
      answer = Math.min(answer, cost);
      continue;
    }

    for (let i = 0; i < oper.length; i++) {
      const [l, r, c] = oper[i];

      const tmpArr = [...curArr];
      [tmpArr[l - 1], tmpArr[r - 1]] = [tmpArr[r - 1], tmpArr[l - 1]];

      const tmpStr = toStr(tmpArr);

      if (!map.has(tmpStr) || map.get(tmpStr) > cost + c) {
        pq.push([tmpStr, cost + c]);
        map.set(tmpStr, cost + c);
      }
    }
  }

  return answer === Infinity ? -1 : answer;
}

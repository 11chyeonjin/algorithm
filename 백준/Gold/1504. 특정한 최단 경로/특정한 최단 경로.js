const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const answer = solution(
    input[0],
    input.slice(1, input.length - 1),
    input[input.length - 1]
  );
  console.log(answer);
});

class PriorityQueue {
  constructor() {
    this.heap = [];
  }

  size() {
    return this.heap.length;
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

function solution([N, E], arr, [v1, v2]) {
  const graph = Array.from({ length: N + 1 }, () => []);

  for (const [from, to, cost] of arr) {
    graph[from].push([to, cost]);
    graph[to].push([from, cost]);
  }

  function dijk(start, target) {
    const pq = new PriorityQueue();

    const cost = Array.from({ length: N + 1 }, () => Infinity);

    pq.push([start, 0]);
    cost[start] = 0;

    while (pq.size() > 0) {
      const [cur, curCost] = pq.pop();

      for (const [next, nextCost] of graph[cur]) {
        if (cost[next] > curCost + nextCost) {
          pq.push([next, curCost + nextCost]);
          cost[next] = curCost + nextCost;
        }
      }
    }

    return cost[target];
  }

  const answer1 = dijk(1, v1) + dijk(v1, v2) + dijk(v2, N);
  const answer2 = dijk(1, v2) + dijk(v1, v2) + dijk(v1, N);

  if (Math.min(answer1, answer2) === Infinity) {
    return -1;
  }

  return Math.min(answer1, answer2);
}

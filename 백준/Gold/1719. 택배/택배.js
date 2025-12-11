const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(input[0], input.slice(1));
  console.log(
    ans
      .slice(1)
      .map((r) => r.slice(1).join(" "))
      .join("\n")
  );
  process.exit();
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

function solution([n, m], arr) {
  const graph = Array.from({ length: n + 1 }, () => []);

  for (const [from, to, cost] of arr) {
    graph[from].push([to, cost]);
    graph[to].push([from, cost]);
  }

  const answer = Array.from({ length: n + 1 }, () =>
    Array.from({ length: n + 1 }, () => "-")
  );

  for (let start = 1; start <= n; start++) {
    const cost = Array.from({ length: n + 1 }, () => Infinity);
    const first = Array.from({ length: n + 1 }, () => "-");

    const pq = new PriorityQueue();
    pq.push([start, 0]);

    while (pq.size() > 0) {
      const [cur, curCost] = pq.pop();

      if (cost[cur] < curCost) {
        continue;
      }

      for (const [next, nextCost] of graph[cur]) {
        const newCost = curCost + nextCost;

        if (cost[next] > newCost) {
          cost[next] = newCost;

          if (cur === start) {
            first[next] = next;
          } else {
            first[next] = first[cur];
          }
        }

        pq.push([next, newCost]);
      }
    }

    for (let j = 1; j <= n; j++) {
      if (j === start) {
        continue;
      }
      answer[start][j] = first[j];
    }
  }

  return answer;
}

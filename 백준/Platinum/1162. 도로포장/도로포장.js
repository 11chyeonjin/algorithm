const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  const ans = solution(input[0], input.slice(1));
  console.log(ans);
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
    } else if (this.heap.length === 1) {
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

    while(true) {
      let lc = p * 2 + 1;
      let rc = p * 2 + 2;
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

function solution([N, _, K], roads) {
  // 1 ~ N, graph[V] = [V, cost]
  const graph = Array.from({ length: N + 1 }, () => []);

  // A안. 도로 포장을 고려하지 않고 다익스트라 진행하며 최적 경로의 비용값을 따로 저장. 이후에 큰 값 최대 K개 제거 처리 => 보장 안될 듯..

  // B안. 도로 포장을 고려하면서 다익스트라..?

  roads.forEach(([from, to, cost]) => {
    graph[from].push([to, cost]);
    graph[to].push([from, cost]);
  });

  const cost = Array.from({ length: N + 1 }, () => Array.from({ length : K + 1 }, () => Infinity));
  const pq = new PriorityQueue;
  pq.push([1, 0, 0]); // [v, cost, 포장 수]
  cost[1][0] = 0;
  
  while(!pq.isEmpty()) {
    const [cur, curCost, curCount] = pq.pop();

    if (cost[cur][curCount] < curCost) {
      continue;
    }

    for (let i = 0; i < graph[cur].length; i++) {
      const [next, targetCost] = graph[cur][i];
      const nextCost = curCost + targetCost;

      // 다음 도로 포장 안하고 진행
      if (cost[next][curCount] > nextCost) {
        cost[next][curCount] = nextCost;
        pq.push([next, nextCost, curCount]);
      }

      // 포장 횟수가 남았다면, 포장 하고 진행
      if (curCount + 1 <= K && cost[next][curCount + 1] > curCost) {
        cost[next][curCount + 1] = curCost;
        pq.push([next, curCost, curCount + 1]);
      }
    }
  }
  
  return Math.min(...cost[N]);
}
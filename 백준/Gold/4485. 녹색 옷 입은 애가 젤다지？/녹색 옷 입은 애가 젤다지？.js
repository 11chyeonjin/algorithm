const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line.split(' ').map(e => +e));
}).on('close', function() {
  const answer = [];

  while(input.length) {
    if (input[0][0] === 0)
      break;

    const arr = input.splice(0, input[0][0] + 1);
    const ans = solution(arr[0][0], arr.slice(1));
    answer.push(ans);
  }

  for (let i = 0; i < answer.length; i++) {
    console.log(`Problem ${i + 1}: ${answer[i]}`);
  }

  process.exit();
})

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
      let p = Math.floor((c - 1) / 2);
      
      if (this.heap[p][2] <= this.heap[c][2]) {
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
      let leftC = p * 2 + 1;
      let rightC = p * 2 + 2;
      let pp = p;
      
      if (leftC < limit && this.heap[leftC][2] < this.heap[pp][2]) {
        pp = leftC;
      }

      if (rightC < limit && this.heap[rightC][2] < this.heap[pp][2]) {
        pp = rightC;
      }

      if (pp === p) {
        break;
      }

      this.swap(pp, p);
      p = pp;
    }
  }
}

const dy = [ 0, 0, 1, -1 ];
const dx = [ 1, -1, 0, 0 ];

function solution(N, arr) {
  const dist = Array.from({ length: N }, () => Array.from({ length: N }, () => Infinity ));

  const pq = new PriorityQueue();
  pq.push([0, 0, arr[0][0]]);
  dist[0][0] = arr[0][0];

  while(!pq.isEmpty()) {
    const [y, x, cost] = pq.pop();

    for (let i = 0; i < 4; i++) {
      const [nextY, nextX] = [y + dy[i], x + dx[i]];

      if (0 <= nextY && nextY < N && 0 <= nextX && nextX < N) {
        if (arr[nextY][nextX] + cost < dist[nextY][nextX]) {
          dist[nextY][nextX] = arr[nextY][nextX] + cost;
          pq.push([nextY, nextX, arr[nextY][nextX] + cost]);
        }
      }
    }
  }

  return dist[N - 1][N - 1];
}
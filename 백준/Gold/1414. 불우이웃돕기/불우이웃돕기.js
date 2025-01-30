const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const N = +input[0];
  const arr = input.slice(1);
  const answer = solution(N, arr);
  console.log(answer);
  process.exit();
});

class PriorityQueue {
  constructor() {
    this.heap = [];
  }

  swap(i, j) {
    [this.heap[i], this.heap[j]] = [this.heap[j], this.heap[i]];
  }

  push(e) {
    this.heap.push(e);
    this.up();
  }

  pop() {
    if (this.isEmpty())
      return null;

    if (this.heap.length === 1)
      return this.heap.pop();

    const root = this.heap[0];
    this.heap[0] = this.heap.pop();
    this.down();
    return root;
  }

  up() {
    let idx = this.heap.length - 1; // 배열의 마지막 인덱스 확인(~차순의 가장 반대되는 값)
    while (idx > 0) {
      let parentI = Math.floor((idx - 1) / 2); // 부모 노드의 인덱스
      
      // 최소 힙 기준
      if (this.heap[parentI][1] <= this.heap[idx][1]) {
        break;
      }

      this.swap(idx, parentI);
      idx = parentI;
    }
  }

  down() {
    let idx = 0;
    const length = this.heap.length;
    while(true) {
      let leftCidx = 2 * idx + 1;
      let rightCidx = 2 * idx + 2;
      let min = idx; // 최소 힙일 경우
      
      // 최소 힙일 경우
      if (leftCidx < length && this.heap[leftCidx][1] < this.heap[min][1]) {
        min = leftCidx;
      }

      // 최소 힙일 경우
      if (rightCidx < length && this.heap[rightCidx][1] < this.heap[min][1]) {
        min = rightCidx;
      }

      if (min === idx)
        break;

      this.swap(min, idx);
      idx = min;
    }
  }

  isEmpty() {
    return this.heap.length === 0;
  }
}

function solution(N, arr) {
  const graph = Array.from({ length: N }, () => []);
  
  let totalLenLength = 0;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      if ('a' <= arr[i][j] && arr[i][j] <= 'z') {
        const lenLength = arr[i][j].charCodeAt() - 'a'.charCodeAt() + 1;
        totalLenLength += lenLength;
        if (i === j) {
          continue;
        }
        
        let flag = false;
        for (let k = 0; k < graph[i].length; k++) {
          if (graph[i][k][0] === j) {
            flag = true;
            graph[i][k][1] = Math.min(graph[i][k][1], lenLength);
          }
        }

        for (let k = 0; k < graph[j].length; k++) {
          if (graph[j][k][0] === i) {
            flag = true;
            graph[j][k][1] = Math.min(graph[j][k][1], lenLength);
          }
        }

        if (!flag) {
          graph[i].push([j, lenLength]);
          graph[j].push([i, lenLength]);
        }
      } else if ('A' <= arr[i][j] && arr[i][j] <= 'Z') {
        const lenLength = arr[i][j].charCodeAt() - 'A'.charCodeAt() + 27;
        totalLenLength += lenLength;
        if (i === j) {
          continue;
        }

        let flag = false;
        for (let k = 0; k < graph[i].length; k++) {
          if (graph[i][k][0] === j) {
            flag = true;
            graph[i][k][1] = Math.min(graph[i][k][1], lenLength);
          }
        }

        for (let k = 0; k < graph[j].length; k++) {
          if (graph[j][k][0] === i) {
            flag = true;
            graph[j][k][1] = Math.min(graph[j][k][1], lenLength);
          }
        }

        if (!flag) {
          graph[i].push([j, lenLength]);
          graph[j].push([i, lenLength]);
        }
      }
    }
  }

  const visited = Array.from({ length: N }, () => false);

  const pq = new PriorityQueue();
  pq.push([0, 0]);

  let totalCost = 0;
  while(!pq.isEmpty()) {
    const [curNode, curCost] = pq.pop();
    
    if (visited[curNode])
      continue;

    visited[curNode] = true;
    totalCost += curCost;

    for (const [next, nextCost] of graph[curNode]) {
      if (!visited[next]) {
        pq.push([next, nextCost]);
      }
    }
  }

  for (const v of visited) {
    if (!v)
      return -1;
  }

  return totalLenLength - totalCost;
}
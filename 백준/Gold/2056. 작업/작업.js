const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  const ans = solution(input[0][0], input.slice(1));
  console.log(ans);
  process.exit();
});

function solution(N, arr) {
  const graph = Array.from({ length: N + 1 }, () => []);
  const cost = Array.from({ length: N + 1 }, () => 0);
  const indeg = Array.from({ length: N + 1 }, () => 0);

  for (let i = 0; i < arr.length; i++) {
    cost[i + 1] = arr[i][0];
    for (let j = 2; j < arr[i].length; j++) {
      graph[arr[i][j]].push(i + 1);
      indeg[i + 1]++;
    }
  }

  const dp = [...cost];

  const queue = [];
  let qi = 0;

  for (let i = 1; i <= N; i++) {
    if (indeg[i] === 0) {
      queue.push(i);
    }
  }
  
  while(qi < queue.length) {
    const cur = queue[qi++];

    for (const next of graph[cur]) {
      dp[next] = Math.max(dp[next], dp[cur] + cost[next]);
      indeg[next]--;

      if (indeg[next] === 0) {
        queue.push(next);
      }
    }
  }

  return Math.max(...dp);
}
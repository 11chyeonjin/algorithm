const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  const ansArr = solution(input[0][0], input.slice(1));
  console.log(ansArr.join('\n'));
})

function solution(N, arr) {
  const cost = Array.from({ length: N + 1 }, () => 0);
  const graph = Array.from({ length: N + 1 }, () => []);
  const indegree = Array.from({ length: N + 1 }, () => 0);
  const dp = Array.from({ length: N + 1 }, () => 0);
  
  for (let i = 0; i < arr.length; i++) {
    cost[i + 1] = arr[i][0];
    dp[i + 1] = arr[i][0];
    for (let j = 1; j < arr[i].length - 1; j++) {
      graph[arr[i][j]].push(i + 1);
      indegree[i + 1]++;
    }
  }

  const queue = [];
  let qi = 0;

  for (let i = 1; i <= N; i++) {
    if (indegree[i] === 0) {
      queue.push(i);
    }
  }

  while(qi < queue.length) {
    const cur = queue[qi++];

    for (const next of graph[cur]) {
      dp[next] = Math.max(dp[next], dp[cur] + cost[next]);
      indegree[next]--;

      if (indegree[next] === 0) {
        queue.push(next);
      }
    }
  }

  return dp.slice(1);
}
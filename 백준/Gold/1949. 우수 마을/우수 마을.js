const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  const ans = solution(input[0][0], input[1], input.slice(2));
  console.log(ans);
  process.exit();
})

function solution(N, town, arr) {
  town = [0, ...town];
  const graph = Array.from({ length: N + 1 }, () => []);
  const dp = Array.from({ length: N + 1 }, () => Array.from({ length: 2 }, () => 0));

  for (const [from, to] of arr) {
    graph[from].push(to);
    graph[to].push(from);
  }

  function dfs(cur, parent) {
    dp[cur][1] = town[cur];
    dp[cur][0] = 0;
    
    for (const next of graph[cur]) {
      if (next === parent) {
        continue;
      }

      dfs(next, cur);

      dp[cur][1] += dp[next][0];
      dp[cur][0] += Math.max(dp[next][0], dp[next][1]);
    }

  }

  dfs(1, 0);

  return Math.max(dp[1][0], dp[1][1]);
}
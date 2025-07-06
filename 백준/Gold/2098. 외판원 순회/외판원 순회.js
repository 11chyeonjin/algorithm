const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line.split(' '));
}).on('close', function() {
  const rst = solution(+input[0][0], input.slice(1).map(r => r.map(Number)));
  console.log(rst);
  process.exit();
})

function solution(N, arr) {
  const graph = Array.from({ length: N }, () => []);

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N; j++) {
      graph[i].push([j, arr[i][j] === 0 ? Infinity : arr[i][j]]);
    }
  }

  const dp = Array.from({ length : N }, () => Array(1 << N).fill(-1));
  // dp[cur][visitedBitMask]

  function dfs(cur, visited) {
    if (visited === (1 << N) - 1) {
      return arr[cur][0] || Infinity;
    }

    if (dp[cur][visited] !== -1) {
      return dp[cur][visited];
    }

    let minCost = Infinity
    for (let i = 0; i < graph[cur].length; i++) {
      const [next, nextCost] = graph[cur][i];

      if ((visited & (1 << next)) || nextCost === Infinity) {
        continue;
      }

      const nextVisited = visited | (1 << next);
      
      minCost = Math.min(minCost, dfs(next, nextVisited) + nextCost);
    }
    dp[cur][visited] = minCost;
    return minCost;
  }

  const answer = dfs(0, 1);
  
  return answer;
}
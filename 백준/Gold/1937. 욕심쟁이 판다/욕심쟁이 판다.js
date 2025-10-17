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

function solution(n, arr) {
  const dp = Array.from({ length: n }, () => Array.from({ length: n }, () => 0));

  const dy = [0, 0, 1, -1];
  const dx = [1, -1, 0, 0];

  function dfs(y, x) {
    const cur = arr[y][x];

    if (dp[y][x] !== 0) {
      return dp[y][x];
    }

    dp[y][x] = 1;

    for (let i = 0; i < 4; i++) {
      const [nextY, nextX] = [y + dy[i], x + dx[i]];

      if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n) {
        if (cur < arr[nextY][nextX]) {
          dp[y][x] = Math.max(dp[y][x], dfs(nextY, nextX) + 1);
        }
      }
    }

    return dp[y][x];
  }

  let answer = -1;
  for (let i = 0; i < n; i++) {
    for (let j = 0; j < n; j++) {
      answer = Math.max(answer, dfs(i, j));
    }
  }

  return answer;
}
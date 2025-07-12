const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  console.log(solution(input[0], input.slice(1)));
  process.exit();
})

const dy = [0, 0, 1, -1];
const dx = [1, -1, 0, 0];

function solution([M, N], arr) {
  const dp = Array.from({ length : M }, _ => Array(N).fill(-1));
  dp[M - 1][N - 1] = 1;

  function dfs(curY, curX) {
    const curV = arr[curY][curX];

    if (dp[curY][curX] !== -1) {
      return dp[curY][curX];
    } else {
      dp[curY][curX] = 0;
    }

    for (let i = 0; i < 4; i++) {
      const [nextY, nextX] = [curY + dy[i], curX + dx[i]];

      if (0 <= nextY && nextY < M && 0 <= nextX && nextX < N) {
        if (curV > arr[nextY][nextX]) {
          dp[curY][curX] += dfs(nextY, nextX);
        }
      }
    }

    return dp[curY][curX];
  }

  const answer = dfs(0, 0);

  return answer;
}
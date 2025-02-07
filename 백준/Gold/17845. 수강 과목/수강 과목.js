const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(e => +e));
}).on('close', function() {
  const [N, K] = input[0];
  const arr = input.slice(1); // 중요도, 공부시간 pair
  const answer = solution(N, K, arr);
  console.log(answer);
  process.exit();
});

function solution(N, K, arr) {
  // 최대 공부시간 N
  // 과목 수 K
  // 냅색
  const dp = Array.from({ length : K }, () => Array.from({ length: N + 1 }, () => 0));

  for (let j = 0; j <= N; j++) {
    if (j >= arr[0][1]) {
      dp[0][j] = arr[0][0];
    }
  }

  for (let cur = 1; cur < K; cur++) {
    for (let j = 0; j <= N; j++) {
      if (j - arr[cur][1] >= 0) {
        dp[cur][j] = Math.max(dp[cur - 1][j - arr[cur][1]] + arr[cur][0], dp[cur - 1][j]) // 포함, 미포함
      } else {
        dp[cur][j] = dp[cur - 1][j];
      }
    }
  }

  return dp[K - 1][N];
}
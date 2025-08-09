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
})

function solution(N, arr) {
  const costArr = arr[0];
  const happyArr = arr[1];

  const dp = Array.from({ length: N }, () => Array.from({ length: 101 }, () => 0)); // dp[사람 인덱스][남은 체력] = 최대 행복

  dp[0][100 - costArr[0]] = happyArr[0];

  for (let i = 1; i < N; i++) {
    for (let j = 0; j < 101; j++) {
      if (j + costArr[i] <= 100) {
        dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j + costArr[i]] + happyArr[i]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  
  return Math.max(...dp[N - 1].slice(1));
}
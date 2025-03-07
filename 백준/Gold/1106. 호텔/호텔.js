const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(e => +e));
}).on('close', function() {
  const answer = solution(input[0][0], input[0][1], input.slice(1));
  console.log(answer);
});

function solution(C, N, arr) {
  // 냅색으로 접근
  const dp = Array.from({ length: N + 1 }, () => Array.from({ length: 2001 }, () => Infinity));
  // arr => {비용, 고객}
  // dp[도시][고객] = 비용

  dp.forEach((r) => {
    r[0] = 0;
  })

  let [firstCost, firstCustom] = arr[0];

  while(firstCustom <= 2000) {
    dp[1][firstCustom] = firstCost;
    firstCost += arr[0][0];
    firstCustom += arr[0][1];
  }
  
  for (let i = 2; i <= N; i++) {
    const [curCost, curCustom] = arr[i - 1];
    for (let j = 0; j <= 2000; j++) {
      let [tmpCost, tmpCustom] = arr[i - 1];

      dp[i][j] = Math.min(dp[i][j], dp[i - 1][j]);
      while(j - tmpCustom >= 0) {
        dp[i][j] = Math.min(dp[i - 1][j - tmpCustom] + tmpCost, dp[i][j]);
        tmpCost += curCost;
        tmpCustom += curCustom;
      }
    }
  }
  
  const answerArr = dp[N].slice(C);

  return Math.min(...answerArr);
}
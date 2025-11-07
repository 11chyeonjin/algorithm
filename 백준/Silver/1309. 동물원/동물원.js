const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = -1;

rl.on('line', function(line) {
  input = line
}).on('close', function() {
  const ans = solution(input);
  console.log(ans);
  process.exit();
});

function solution(num) {
  const dp = [0, 3, 7];

  for (let i = 3; i <= num; i++) {
    dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
  }
  
  return dp[num];
}
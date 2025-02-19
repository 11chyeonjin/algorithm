const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(+line);
}).on('close', function() {
  const answer = solution(input[0]);
  console.log(answer);
});

function solution(n) {
  const fibo = [ BigInt(0), BigInt(1) ];

  for (let i = 2; i <= n; i++) {
    fibo.push(fibo[i - 2] + fibo[i - 1]);
  }

  return String(fibo[n]);
}
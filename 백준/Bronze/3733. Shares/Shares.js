const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  const ans = solution(input);
  console.log(ans.join('\n'));
  process.exit();
});

function solution(arr) {
  const answer = [];

  for (const [N, S] of arr) {
    answer.push(Math.floor(S / (N + 1)));
  }

  return answer;
}
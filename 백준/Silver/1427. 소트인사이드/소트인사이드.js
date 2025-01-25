const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const answer = solution(input[0]);
  console.log(answer.join(''));
  process.exit();
});

function solution(N) {
  const arr = [];

  for (let i = 0; i < N.length; i++) {
    arr.push(+N.charAt(i));  
  }

  arr.sort((a, b) => b - a);

  return arr;
}
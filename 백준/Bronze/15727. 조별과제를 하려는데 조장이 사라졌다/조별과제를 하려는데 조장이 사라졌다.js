const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
})

let input;

readline.on('line', function(line) {
  input = line
}).on('close', function() {
  console.log(solution(input));
  process.exit();
})

function solution(n) {
  if (n % 5 === 0) {
    return Math.floor(n / 5);
  } else {
    return Math.floor(n / 5 + 1);
  }
}
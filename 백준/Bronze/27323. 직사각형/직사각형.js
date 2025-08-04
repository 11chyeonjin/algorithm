const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(+line);
}).on('close', function() {
  const ans = solution(input);
  console.log(ans);
  process.exit();
})

function solution(arr) {
  return arr[0] * arr[1];
}
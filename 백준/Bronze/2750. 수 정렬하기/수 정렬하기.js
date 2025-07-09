const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const rst = solution(input.slice(1).map(Number));
  console.log(rst.join('\n'));
  process.exit();
})

function solution(arr) {
  return arr.sort((a, b) => a - b);
}
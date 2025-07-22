const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.trim());
}).on('close', function() {
  console.log(solution(input));
  process.exit();
})

function solution(arr) {
  const map = new Map([
    ['black', 0],
    ['brown', 1],
    ['red', 2],
    ['orange', 3],
    ['yellow', 4],
    ['green', 5],
    ['blue', 6],
    ['violet', 7],
    ['grey', 8],
    ['white', 9]
  ]);

  return (map.get(arr[0]) * 10 + map.get(arr[1])) * (10 ** map.get(arr[2]));
}
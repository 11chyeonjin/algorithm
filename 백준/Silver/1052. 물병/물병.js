const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", function(line) {
  input.push(line);
}).on("close", function() {
  solution(input);
  process.exit();
});

function solution(arr) {
  const [N, K] = input[0].split(' ').map((el) => parseInt(el));
  let result = 0;

  while (bottleCount(N + result) > K) {
    result++;
  }

  console.log(result);
}

function bottleCount(num) {
  let cnt = 0;

  while(num > 0) {
    if (num % 2 === 1) {
      cnt++;
    }
    num = Math.floor(num / 2);
  }
  
  return cnt;
}
const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  console.log(solution(input[0], input[1]));
  process.exit();
});

function solution([N, M], arr) {
  for (let i = arr.length - 2; i >= 0; i--) {
    arr[i] += arr[i + 1];
  }

  for (let i = arr.length - 1; i >= 0; i--) {
    if (arr[i] >= M) {
      return i + 1;
    }
  }

  return -1;
}

const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(input[0][0], input[1], input[2]);
  console.log(ans[0]);
  console.log(ans[1].join(" "));
  process.exit();
});

function solution(N, arr, [T, P]) {
  let tNum = 0;

  for (const e of arr) {
    tNum += Math.ceil(e / T);
  }

  return [tNum, [Math.floor(N / P), N % P]];
}

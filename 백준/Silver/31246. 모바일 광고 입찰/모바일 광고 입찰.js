const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(input[0], input.slice(1));
  console.log(ans);
  process.exit();
});

function solution([N, K], arr) {
  let cnt = 0;

  const sol = [];

  for (const [a, b] of arr) {
    if (a >= b) {
      cnt++;
    } else {
      sol.push(b - a);
    }
  }

  sol.sort((a, b) => a - b);

  let ans = 0;
  for (let i = 0; i < sol.length; i++) {
    if (K <= cnt) {
      return ans;
    }

    cnt++;
    if (sol[i] <= ans) {
      continue;
    } else {
      ans = sol[i];
    }
  }

  return ans;
}

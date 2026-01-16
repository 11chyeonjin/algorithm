const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(input[0][0], input[1]);
  console.log(ans.join(" "));
  process.exit();
});

function solution(N, arr) {
  const ans = Array.from({ length: N }, () => 0);

  const stack = [];
  stack.push([N - 1, arr[N - 1]]);

  for (let i = N - 2; i >= 0; i--) {
    const cur = arr[i];

    while (stack.length && stack[stack.length - 1][1] < cur) {
      const [idx, _] = stack.pop();
      ans[idx] = i + 1;
    }

    stack.push([i, cur]);
  }

  return ans;
}

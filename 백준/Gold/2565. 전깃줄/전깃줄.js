const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(input[0][0], input.slice(1));
  console.log(ans);
  process.exit();
});

function solution(N, arr) {
  arr = arr.sort((a, b) => a[0] - b[0]).map(([_, to]) => to);

  const dp = Array.from({ length: N + 1 }, () => 0);

  // console.log("============");
  // console.log(arr.join(" "));

  for (const cur of arr) {
    let i = 0;
    while (i <= N) {
      if (dp[i] > cur || dp[i] === 0) {
        dp[i] = cur;
        break;
      }
      i++;
    }
    // console.log(dp.filter((e) => e !== 0).join(" "));
  }

  return N - dp.indexOf(0);
}

const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(input[0][0], input[1], input[2][0]);
  console.log(ans);
  process.exit();
});

function solution(N, pArr, M) {
  const dp = Array.from({ length: M + 1 }, () => "");

  function comp(strA, strB) {
    if (strA.length === strB.length) {
      return strA > strB ? strA : strB;
    }

    return strA.length > strB.length ? strA : strB;
  }

  for (let cur = 0; cur <= M; cur++) {
    for (let num = 0; num < N; num++) {
      const cost = pArr[num];

      if (cur - cost < 0) {
        continue;
      }

      const prev = dp[cur - cost];

      if (prev === "0") {
        continue;
      }

      dp[cur] = comp(dp[cur], prev + String(num));
    }
  }

  let ans = "";
  for (let c = 0; c <= M; c++) {
    ans = comp(ans, dp[c]);
  }

  return ans;
}

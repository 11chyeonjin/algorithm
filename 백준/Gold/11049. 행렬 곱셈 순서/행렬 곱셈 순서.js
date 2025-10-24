const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const answer = solution(input[0][0], input.slice(1));
  console.log(answer);
  process.exit();
});

function solution(N, arr) {
  const dp = Array.from({ length: N }, () =>
    Array.from({ length: N }, () => Infinity)
  );

  for (let i = 0; i < N; i++) {
    dp[i][i] = 0;
  }

  for (let size = 1; size <= N - 1; size++) {
    for (let start = 0; start + size <= N - 1; start++) {
      let end = start + size;

      for (let t = start; t < end; t++) {
        const cost =
          dp[start][t] +
          dp[t + 1][end] +
          arr[start][0] * arr[t][1] * arr[end][1];

        dp[start][end] = Math.min(dp[start][end], cost);
      }
    }
  }

  return dp[0][N - 1];
}

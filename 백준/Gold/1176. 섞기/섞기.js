const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

(async () => {
  const input = [];

  for await (const line of rl) {
    input.push(line);
  }

  const ans = solution(
    input[0].split(" ").map(Number),
    input.slice(1).map(Number),
  );
  console.log(ans);

  process.exit();
})();

function solution([N, K], arr) {
  const dp = Array.from({ length: 1 << N }, () =>
    Array.from({ length: N }, () => 0),
  );

  for (let i = 0; i < N; i++) {
    dp[1 << i][i] = 1;
  }

  for (let m = 1; m < 1 << N; m++) {
    for (let lastI = 0; lastI < N; lastI++) {
      for (let nextI = 0; nextI < N; nextI++) {
        if (m & (1 << nextI)) {
          continue;
        }

        if (Math.abs(arr[lastI] - arr[nextI]) > K) {
          dp[m | (1 << nextI)][nextI] += dp[m][lastI];
        }
      }
    }
  }

  let answer = 0;
  for (let i = 0; i < N; i++) {
    answer += dp[(1 << N) - 1][i];
  }

  return answer;
}

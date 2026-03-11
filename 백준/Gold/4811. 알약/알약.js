const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

(async () => {
  const input = [];

  for await (const line of rl) {
    input.push(Number(line));
  }

  const ans = [];
  for (let i = 0; i < input.length; i++) {
    if (input[i] === 0) break;
    ans.push(solution(input[i]).toString());
  }
  console.log(ans.join("\n"));

  process.exit();
})();

function solution(N) {
  const dp = Array.from({ length: N + 1 }, () =>
    Array.from({ length: N + 1 }, () => -1n),
  );

  function dfs(w, h) {
    if (w === 0 && h === 0) {
      return 1n;
    }

    if (dp[w][h] !== -1n) {
      return dp[w][h];
    }

    let rst = 0n;

    if (w > 0) {
      rst += dfs(w - 1, h + 1);
    }

    if (h > 0) {
      rst += dfs(w, h - 1);
    }

    dp[w][h] = rst;
    return rst;
  }

  return dfs(N, 0);
}

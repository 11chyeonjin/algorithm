const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(input[0][0], input[1][0], input.slice(2));
  console.log(ans);
  process.exit();
});

function solution(N, M, arr) {
  const base = new Set();
  const topo = Array.from({ length: N + 1 }, () => []); // topo[재료] = [[제작가능부품, 필요수량]]
  const indegree = Array.from({ length: N + 1 }, () => 0); // indegree[부품] = 필요한 재료 종류
  const dp = Array.from({ length: N + 1 }, () =>
    Array.from({ length: N + 1 }, () => 0)
  );

  for (const [x, y, k] of arr) {
    topo[y].push([x, k]);
    indegree[x]++;
  }

  const q = [];
  let qi = 0;

  for (let i = 1; i <= N; i++) {
    if (indegree[i] === 0) {
      q.push(i);
      dp[i][i] = 1;
      base.add(i);
    }
  }

  while (qi < q.length) {
    const cur = q[qi++];

    for (const [next, am] of topo[cur]) {
      indegree[next]--;

      if (indegree[next] === 0) {
        q.push(next);
      }

      for (let i = 1; i <= N; i++) {
        dp[next][i] += dp[cur][i] * am;
      }
    }
  }

  const ans = [];

  for (let i = 1; i <= N; i++) {
    if (base.has(i)) {
      ans.push(`${i} ${dp[N][i]}`);
    }
  }

  return ans.join("\n");
}

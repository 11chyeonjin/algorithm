const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  let T = input[0][0];
  let i = 0;
  while (T--) {
    const ans = solution(
      input[++i][0],
      input[++i],
      input[++i][0],
      input.slice(i + 1, i + input[i][0] + 1)
    );
    console.log(ans);
    i += input[i][0];
  }
  process.exit();
});

function solution(n, nArr, m, mArr) {
  const vs = Array.from(
    { length: n + 1 },
    () => Array.from({ length: n + 1 }, () => false) // [win][lose]
  );
  const indegree = Array.from({ length: n + 1 }, () => 0);

  for (let w = 0; w < n; w++) {
    const win = nArr[w];

    for (let l = w + 1; l < n; l++) {
      const lose = nArr[l];

      if (vs[win][lose] === false) {
        vs[win][lose] = true;
        indegree[lose]++;
      }
    }
  }

  for (const [win, lose] of mArr) {
    if (vs[win][lose] === true) {
      vs[win][lose] = false;
      indegree[lose]--;
      vs[lose][win] = true;
      indegree[win]++;
    } else {
      vs[win][lose] = true;
      indegree[lose]++;
      vs[lose][win] = false;
      indegree[win]--;
    }
  }

  const q = [];
  let qi = 0;
  for (let i = 1; i <= n; i++) {
    if (indegree[i] === 0) {
      q.push(i);
    }
  }

  const result = [];

  for (let i = 0; i < n; i++) {
    if (qi >= q.length) {
      return "IMPOSSIBLE";
    }

    if (q.length - qi > 1) {
      return "?";
    }

    const cur = q[qi++];
    result.push(cur);
    for (let j = 1; j <= n; j++) {
      if (vs[cur][j] === true) {
        indegree[j]--;
      }

      if (indegree[j] === 0 && !result.includes(j)) {
        q.push(j);
      }
    }
  }

  return result.join(" ");
}

const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const rst = solution(input[0], input.slice(1));
  console.log(rst);
  process.exit();
});

function solution([N, M], arr) {
  const topo = Array.from({ length: N + 1 }, () => []);
  const indeg = Array.from({ length: N + 1 }, () => 0);

  for (const [a, b] of arr) {
    topo[a].push(b);
    indeg[b]++;
  }

  const q = [];
  let qi = 0;

  for (let i = 1; i <= N; i++) {
    if (indeg[i] === 0) {
      q.push(i);
    }
  }

  let curL = q.length;
  let curS = 1;
  const done = new Map();
  while (done.size < N) {
    if (qi === curL) {
      curS++;
      for (let i = 1; i <= N; i++) {
        if (indeg[i] === 0 && !done.has(i)) {
          q.push(i);
        }
      }
      curL = q.length;
    }

    const cur = q[qi++];
    done.set(cur, curS);

    for (const next of topo[cur]) {
      indeg[next]--;
    }
  }

  const rst = [...done];
  rst.sort((a, b) => a[0] - b[0]);

  return rst.map(([a, s]) => s).join(" ");
}

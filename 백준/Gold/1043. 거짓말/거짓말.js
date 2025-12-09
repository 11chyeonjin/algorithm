const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(
    input[0],
    input[1].slice(1),
    input.slice(2).map((a) => a.slice(1))
  );
  console.log(ans);
  process.exit();
});

function solution([N, M], trueArr, partyArr) {
  let parent = [];
  let size = [];

  function init(n) {
    parent = Array.from({ length: n + 1 }, (_, i) => i);
    size = Array.from({ length: n + 1 }, () => 1);
  }

  function find(x) {
    if (parent[x] !== x) {
      parent[x] = find(parent[x]);
    }

    return parent[x];
  }

  function union(a, b) {
    a = find(a);
    b = find(b);

    if (a === b) {
      return;
    }

    if (size[a] < size[b]) {
      [a, b] = [b, a];
    }

    parent[b] = a;
    size[a] += size[b];
  }

  init(N);

  for (const p of partyArr) {
    for (let i = 0; i < p.length - 1; i++) {
      union(p[i], p[i + 1]);
    }
  }

  let answer = 0;

  for (const p of partyArr) {
    let flag = false;
    for (const t of trueArr) {
      if (find(p[0]) === find(t)) {
        flag = true;
        break;
      }
    }

    if (!flag) {
      answer++;
    }
  }

  return answer;
}

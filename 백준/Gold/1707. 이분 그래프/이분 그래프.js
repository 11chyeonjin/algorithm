const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  let K = input[0][0];
  let i = 1;
  while (K--) {
    const ans = solution(
      input[i][0],
      input[i][1],
      input.slice(i + 1, i + 1 + input[i][1])
    );
    i += input[i][1] + 1;
    console.log(ans);
  }
});

function solution(V, E, arr) {
  const graph = Array.from({ length: V + 1 }, () => []);

  for (const [a, b] of arr) {
    graph[a].push(b);
    graph[b].push(a);
  }

  const visited = Array.from({ length: V + 1 }, () => 0);

  function bfs(start) {
    const q = [start];
    let qi = 0;
    visited[start] = 1;

    while (qi < q.length) {
      const cur = q[qi++];
      const curV = visited[cur];

      for (let i = 0; i < graph[cur].length; i++) {
        const next = graph[cur][i];

        if (visited[next] === 0) {
          q.push(next);
          visited[next] = -curV;
        } else if (visited[next] === curV) {
          return false;
        }
      }
    }

    return true;
  }

  for (let i = 1; i <= V; i++) {
    if (visited[i] === 0) {
      const rst = bfs(i);

      if (!rst) {
        return "NO";
      }
    }
  }

  return "YES";
}

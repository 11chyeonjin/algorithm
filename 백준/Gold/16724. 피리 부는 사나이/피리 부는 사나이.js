const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  const answer = solution(input[0].split(" ").map(Number), input.slice(1));
  console.log(answer);
});

function solution([N, M], arr) {
  const target = Array.from({ length: N }, () =>
    Array.from({ length: M }, () => [])
  );

  function go(y, x) {
    const q = [[y, x]];
    let qi = 0;

    const dir = {
      U: [-1, 0],
      D: [1, 0],
      L: [0, -1],
      R: [0, 1],
    };

    const visited = new Set();

    let rst = [];

    while (qi < q.length) {
      const [curY, curX] = q[qi++];

      if (target[curY][curX].length !== 0) {
        rst = target[curY][curX];
        break;
      }

      const curStr = `${curY},${curX}`;

      if (visited.has(curStr)) {
        rst = [curY, curX];
        break;
      }

      visited.add(curStr);

      const [nextY, nextX] = [
        curY + dir[arr[curY][curX]][0],
        curX + dir[arr[curY][curX]][1],
      ];
      q.push([nextY, nextX]);
    }

    for (const str of visited) {
      const [fy, fx] = str.split(",").map(Number);
      target[fy][fx] = rst;
    }
  }

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      go(i, j);
    }
  }

  const answer = new Set();

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      answer.add(target[i][j]);
    }
  }

  return answer.size;
}

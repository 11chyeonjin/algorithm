const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  const ans = solution(input[0].split(" ").map(Number), input.slice(1));
  console.log(ans);
});

function solution([M, N], arr) {
  const cost = Array.from({ length: N }, () =>
    Array.from({ length: M }, () => Infinity)
  );

  const dy = [0, 0, 1, -1];
  const dx = [1, -1, 0, 0];

  const deq = [];

  deq.push([0, 0]);
  cost[0][0] = 0;

  while (deq.length) {
    const [curY, curX] = deq.shift();

    for (let i = 0; i < 4; i++) {
      const [nextY, nextX] = [curY + dy[i], curX + dx[i]];

      if (0 <= nextY && nextY < N && 0 <= nextX && nextX < M) {
        const c = arr[nextY][nextX] === "1" ? 1 : 0;

        if (cost[nextY][nextX] > cost[curY][curX] + c) {
          cost[nextY][nextX] = cost[curY][curX] + c;

          if (c === 1) {
            deq.push([nextY, nextX]);
          } else {
            deq.unshift([nextY, nextX]);
          }
        }
      }
    }
  }

  return cost[N - 1][M - 1];
}

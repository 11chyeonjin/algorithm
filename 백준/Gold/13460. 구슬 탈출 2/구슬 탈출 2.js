const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

(async () => {
  const input = [];

  for await (const line of rl) {
    input.push(line);
  }

  const ans = solution(input[0].split(' ').map(Number), input.slice(1));

  console.log(ans);

  process.exit();
})();

function solution([N, M], bb) {
  const board = bb.map(s => s.split(''));

  let blue, red;

  for (let i = 0; i < N; i++) {
    for (let j = 0; j < M; j++) {
      if (board[i][j] === 'B') {
        blue = [i, j];
        board[i][j] = '.';
      } else if (board[i][j] === 'R') {
        red = [i, j];
        board[i][j] = '.';
      }
    }
  }

  const dy = [0, 0, 1, -1];
  const dx = [1, -1, 0, 0];

  function move(dir, cur) {
    let [y, x] = cur;
    let moved = 0;

    while (true) {
      const ny = y + dy[dir];
      const nx = x + dx[dir];

      if (board[ny][nx] === '#') 
        return [[y, x], moved, false];

      y = ny; 
      x = nx; 
      moved++;

      if (board[y][x] === 'O') 
        return [[y, x], moved, true];
    }
  }

  function bfs(startR, startB) {
    const q = [];
    let qi = 0;

    const visited = new Set();
    visited.add(`${startR[0]},${startR[1]},${startB[0]},${startB[1]}`);

    q.push([startR, startB, 0]);

    while (qi < q.length) {
      const [cR, cB, turn] = q[qi++];

      if (turn >= 10) {
        continue;
      }

      for (let dir = 0; dir < 4; dir++) {
        const [nR, rMove, rGoal] = move(dir, cR);
        const [nB, bMove, bGoal] = move(dir, cB);

        if (bGoal) {
          continue;
        }

        if (rGoal) 
          return turn + 1;

        let [ry, rx] = nR;
        let [by, bx] = nB;

        if (ry === by && rx === bx) {
          if (rMove > bMove) {
            ry -= dy[dir];
            rx -= dx[dir];
          } else {
            by -= dy[dir];
            bx -= dx[dir];
          }
        }

        const k = `${ry},${rx},${by},${bx}`;

        if (visited.has(k)) {
          continue;
        }
        visited.add(k);

        q.push([[ry, rx], [by, bx], turn + 1]);
      }
    }

    return -1;
  }

  return bfs(red, blue);
}

const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

readline.on("line", function(line) {
  input.push(line.split(' '));
}).on("close", function() {
  const answer = [];
  const T = +input.shift();
  for(let i = 0; i < T; i++) {
    const N = +input[i * 3];
    const cur = input[i * 3 + 1].map(e => +e);
    const target = input[i * 3 + 2].map(e => +e);
    answer.push(solution(N, cur, target));
  }
  console.log(answer.join('\n'));
  process.exit();
});

function solution(N, ini, target) {
  const dy = [ -2, -2, -1, -1, 1, 1, 2, 2 ];
  const dx = [ -1, 1, -2, 2, -2, 2, -1, 1 ];

  const visited = Array.from({ length : N }, () => Array(N).fill(false));
  
  const queue = [];
  queue.push([...ini, 0]);
  let qF = 0;

  let answer = -1;
  
  while(qF < queue.length) {
    const curY = queue[qF][0];
    const curX = queue[qF][1];
    const curD = queue[qF][2];
    qF++;

    if (curY === target[0] && curX === target[1]) {
      answer = curD;
      break;
    }

    for (let i = 0; i < 8; i++) {
      const next = [curY + dy[i], curX + dx[i]];
      
      if (0 <= next[0] && next[0] < N && 0 <= next[1] && next[1] < N) {
        if (!visited[next[0]][next[1]]) {
          queue.push([...next, curD + 1]);
          visited[next[0]][next[1]] = true;
        }
      }
    }
  }

  return answer;
}
const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout, 
});

const input = [];

rl.on('line', function(line) {
  input.push(Number(line));
}).on('close', function() {
  const answer = solution(input[0], input[1]);
  console.log(answer);
  process.exit();
});

function solution(start, target) {
  const targetV = parseInt(target, 2);

  const q = [parseInt(start, 2)];
  let qIndex = 0;

  const visited = new Map();
  visited.set(parseInt(start, 2), 1);

  let answer = -1;

  while(qIndex < q.length) {
    let cur = q[qIndex];
    let bCur = cur.toString(2);
    let curTime = visited.get(cur);
    qIndex++;

    if (cur === targetV) {
      answer = curTime;
      break;
    }

    let next = cur + 1;
    if (!visited.has(next)) {
      visited.set(next, curTime + 1);
      q.push(next);
    }

    next = cur - 1;
    if (next >= 0 && !visited.has(next)) {
      visited.set(next, curTime + 1);
      q.push(next);
    }

    for (let i = 0; i < bCur.length - 1; i++) {
      next = cur ^ (1 << i);
      if (!visited.has(next)) {
        visited.set(next, curTime + 1);
        q.push(next);
      }
    }
  }

  return answer - 1;
}
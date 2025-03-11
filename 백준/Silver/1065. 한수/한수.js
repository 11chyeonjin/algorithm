const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function (line) {
  input.push(line);
}).on('close', function () {
  const answer = solution(+input[0]);
  console.log(answer);
});

function solution(N) {
  let answer = 0;

  for (let num = 1; num <= N; num++) {
    if (num < 100) {
      answer++;
      continue;
    }
    
    const numStr = num.toString();
    let flag = true;

    const numDiff = +numStr[0] - numStr[1];
    for (let i = 1; i < numStr.length - 1; i++) {
      if (+numStr[i] - numStr[i + 1] !== numDiff) {
        flag = false;
        break;
      }
    }

    if (flag) {
      answer++;
    }
  }

  return answer;
}
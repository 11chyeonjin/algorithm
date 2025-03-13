const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' '));
}).on('close', function() {
  const answer = solution(+input[0][0], +input[0][1], input[1].map(e => +e));
  console.log(answer);
  process.exit();
});

function solution(N, S, numArr) {
  let [front, back] = [0, 0];

  let curSum = 0;
  let answer = Infinity;

  while(back < N) {
    curSum += numArr[back];

    while(curSum >= S) {
      curSum -= numArr[front];
      answer = Math.min(answer, back - front + 1);
      front++;
    }

    back++;
  }

  if (answer === Infinity) {
    return 0;
  }

  return answer;
}

const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const t = +input[0];
  let idx = 1;
  const answer = [];
  for (let i = 0; i < t; i++) {
    const n = +input[idx++];
    const numArr = input.slice(idx, idx + n);
    idx += n;
    const result = solution(numArr);
    answer.push(result);
  }
  console.log(answer.join('\n'));
  process.exit();
});

function solution(numArr) {
  numArr.sort();
  for (let i = 0; i < numArr.length - 1; i++) {
    const prev = numArr[i];
    const post = numArr[i + 1];
    if (prev === post.slice(0, prev.length)) {
      return 'NO';
    }
  }
  return 'YES';
}
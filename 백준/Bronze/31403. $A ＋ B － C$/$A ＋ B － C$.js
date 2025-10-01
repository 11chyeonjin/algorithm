const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on('line', function(line) {
  input.push(line);
  input = input.map(Number);
}).on('close', function() {
  const ans = solution(input);
  console.log(ans.join('\n'));
  process.exit();
});

function solution(arr) {
  const answer = [];

  arr[2] *= -1;

  let num = 0;
  let str = "";

  for (let i = 0; i < 3; i++) {
    num += arr[i];
    if (i === 2) {
      str = (Number(str) + arr[i]).toString();
    } else {
      str += arr[i];
    }
  }

  answer.push(num, str);

  return answer;
}
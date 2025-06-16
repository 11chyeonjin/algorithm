const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(+line);
}).on('close', function() {
  const answer = solution(input[0]);
  console.log(answer);
  process.exit();
});

function solution(X) {
  let binaryX = X.toString(2);

  let rst = 0;

  binaryX.split('').forEach((e) => {
    if (e === '1') {
      rst++;
    }
  })

  return rst;
}
const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  const rst = [];
  let T = input[0][0];
  let curI = 1;
  while (T--) {
    const [m, n] = input[curI++];
    rst.push(solution(m, n, input.slice(curI, curI + m)));
    curI += m;
  }
  console.log(rst.join('\n'));
  process.exit();
});

function solution(m, n, arr) {
  let rst = 0;

  for (let j = 0; j < n; j++) {
    let count = 0;
    let curBoxSum = 0;
    for (let i = 0; i < m; i++) {
      if (arr[i][j] === 1) {
        count++;
        curBoxSum += i;
      }
    }

    if (count === 0)
      continue;

    let targetSum = 0;
    for (let i = m - 1; i > m - count - 1; i--) {
      targetSum += i;
    }

    rst += targetSum - curBoxSum;
  }

  return rst;
}
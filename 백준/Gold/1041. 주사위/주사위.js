const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' ').map(Number));
}).on('close', function() {
  console.log(solution(input[0][0], input[1]));
  process.exit();
})

function solution(N, arr) {
  // A-F B-E C-D
  // 모서리 꼭짓점 3면
  // 나머지 중 평범한 모서리 2면
  // 나머지 1면
  
  if (N === 1) {
    arr.sort((a, b) => a - b);
    let sum = 0;
    for (let i = 0; i < 5; i++) {
      sum += arr[i];
    }
    return sum;
  }

  const dice = [[arr[0], arr[5]], [arr[1], arr[4]], [arr[2], arr[3]]];

  let answer = 0;
  
  // 위 꼭짓점 4개
  let v = 0;
  dice.forEach(([a, b]) => {
    v += Math.min(a, b);
  });

  answer += 4 * v;

  // 아랫 꼭짓점 4개, 윗 모서리
  let c = v;
  let tmpArr = [];
  dice.forEach(([a, b]) => {
    tmpArr.push(Math.min(a, b));
  })

  c -= Math.max(...tmpArr);

  answer += 4 * c;

  answer += 8 * c * (N - 2);

  // 아랫 모서리, 면
  let s = Math.min(...tmpArr);

  answer += 4 * s * (N - 2);

  answer += 5 * s * ((N - 2) ** 2);

  return answer;
}
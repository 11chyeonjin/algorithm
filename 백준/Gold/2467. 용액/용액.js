const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
})

let input = [];

readline.on('line', function(line) {
  input.push(line.split(' '));
}).on('close', function() {
  const N = Number(input[0]);
  const liquidArr = input[1].map(Number);
  const result = solution(N, liquidArr);
  console.log(result.join(' '));
  process.exit();
})

function solution(N, liquidArr) {
  liquidArr.sort((a, b) => a - b);
  let [leftAns, rightAns] = [0, 0];

  let leftIdx = 0;
  let rightIdx = N - 1;
  let absMin = Infinity;

  while (leftIdx < rightIdx) {
      let sum = liquidArr[leftIdx] + liquidArr[rightIdx];
      let absSum = Math.abs(sum);

      if (absSum < absMin) {
        absMin = absSum;
        leftAns = liquidArr[leftIdx];
        rightAns = liquidArr[rightIdx];
      }

      if (sum === 0) {
        break;
      } else if (sum < 0) {
        leftIdx++;
      } else {
        rightIdx--;
      }
  }
  return [leftAns, rightAns];
}

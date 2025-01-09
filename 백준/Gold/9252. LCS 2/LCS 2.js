const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

readline.on('line', function(line) {
  input.push(line.split(''));
}).on('close', function() {
  let s1 = input[0];
  let s2 = input[1];
  let answer = solution(s1, s2);
  console.log(answer.join('\n'));
  process.exit();
});

function solution(s1, s2) {
  let dp = Array.from({ length: s1.length + 1 }, () => Array(s2.length + 1).fill(0));
  
  for (let i = 0; i < s1.length; i++) {
    for (let j = 0; j < s2.length; j++) {
      if (s1[i] === s2[j]) {
        dp[i + 1][j + 1] = dp[i][j] + 1;
      } else {
        dp[i + 1][j + 1] = Math.max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }

  const answerLength = dp[s1.length][s2.length];

  let curV = answerLength;
  let curI = s1.length;
  let curJ = s2.length;

  const answerArr = [];

  while(true) {
    if (dp[curI][curJ] === 0)
      break;

    if (dp[curI - 1][curJ] === curV) {
      curI--;
      continue;
    }

    if (dp[curI][curJ - 1] === curV) {
      curJ--;
      continue;
    }

    answerArr.push(s1[curI - 1]);
    curV--;
    curI--;
    curJ--;
  }

  return [answerLength, answerArr.reverse().join('')];
}
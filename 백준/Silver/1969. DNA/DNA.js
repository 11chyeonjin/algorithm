const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line.split(' '));
}).on('close', function() {
  const [N, M] = [+input[0][0], +input[0][1]];
  const dnaArr = input.slice(1).map(arr => arr[0]);
  const answer = solution(N, M, dnaArr);
  console.log(answer.join('\n'));
  process.exit();
});

function solution(N, M, dnaArr) {
  const nu = ['A', 'C', 'G', 'T'];


  let answerStr = '';
  let answerValue = 0;
  
  for (let i = 0; i < M; i++) {
    const cnt = Array.from({ length : 4 }, () => 0);

    dnaArr.forEach(dna => {
      const cur = dna.charAt(i);
      switch(cur) {
        case 'A':
          cnt[0]++;
          break;
        case 'C':
          cnt[1]++;
          break;
        case 'G':
          cnt[2]++;
          break;
        case 'T':
          cnt[3]++;
          break;
        default:
          break;
      }
    })

    const maxCnt = Math.max(...cnt);
    const maxIdx = cnt.indexOf(maxCnt);
    answerValue += N - maxCnt;
    answerStr += nu[maxIdx];
  } 

  return [answerStr, answerValue];
}
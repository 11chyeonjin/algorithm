const rl = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on('line', function(line) {
  input.push(line);
}).on('close', function() {
  const wordArr = input.slice(1);
  const answer = solution(wordArr);
  console.log(answer);
  process.exit();
});

function solution(wordArr) {
  let answer = 0;
  for (const word of wordArr) {
    const set = new Set();
    let pre = '';
    let flag = true; // 조건에 만족하지 못할 경우 false
    for (let i = 0; i < word.length; i++) {
      const cur = word.charAt(i);
      if (pre !== cur) {
        // 앞선 문자와 다를경우
        if (pre !== '') {
          // 문자열의 첫 문자가 아닌 경우
          if (set.has(cur)) {
            // 그룹 단어 불만족
            flag = false;
            break;
          } else {
            // 그룹 단어 만족
            set.add(pre);
            pre = cur;
          }
        } else {
          pre = cur;
        }
      }
    }

    if (flag) {
      answer++;
    }
  }

  return answer;
}
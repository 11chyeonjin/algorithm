const readline = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

readline.on("line", function(line) {
  input.push(line.split(' '));
}).on("close", function() {
  const answer = [];
  let T = +input[0][0];
  for (let i = 1; i <= T; i++) {
    const [N, M] = [+input[i][0], +input[i][1]];
    const tResult = solution(N, M);
    answer.push(tResult);
  }
  console.log(answer.join('\n'));
  process.exit();
});

function facto(num) {
  if (num <= 1) {
    return 1;
  }
  return facto(num - 1) * num;
}

function solution(N, M) {
  // 다리는 겹쳐질 수 없으므로, mCn
  return Math.round(facto(M) / facto(M - N) / facto(N));
}
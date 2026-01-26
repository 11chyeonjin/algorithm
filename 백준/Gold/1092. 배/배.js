const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line.split(" ").map(Number));
}).on("close", function () {
  const ans = solution(input[0][0], input[1], input[2][0], input[3]);
  console.log(ans);
  process.exit();
});

function solution(N, cArr, M, bArr) {
  cArr.sort((a, b) => b - a);
  bArr.sort((a, b) => b - a);

  if (bArr[0] > cArr[0]) return -1;

  let time = 0;

  while (bArr.length > 0) {
    let boxIdx = 0;

    for (let i = 0; i < N; i++) {
      while (boxIdx < bArr.length) {
        if (cArr[i] >= bArr[boxIdx]) {
          bArr.splice(boxIdx, 1);
          break;
        }
        boxIdx++;
      }
    }

    time++;
  }

  return time;
}

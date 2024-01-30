const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on("line", function(line) {
  input.push(line);
}).on("close", function() {
  solution();
  process.exit();
});

function solution() {
  let N = parseInt(input[0]);
  let arr = input[1].split(' ').map((el) => parseInt(el));

  let max_value = -1;

  let dp = new Array(arr.length).fill(0);

  // 모든 변수는 해당되는 빌딩의 번호, X 좌표를 나타냄
  for (let i = 0; i < arr.length; i++) { // 좌측 빌딩 i
    let cnt = 0;
    for (let j = i + 1; j < arr.length; j++) { // 우측 빌딩 j 
      let flag = true;
      for (let k = i + 1; k < j; k++) { // 사이 빌딩 k
        if (arr[k] >= (arr[j] - arr[i]) / (j - i) * (k - i) + arr[i]) {
          flag = false;
          break;
        }
      }
      if (flag) {
        dp[i]++;
        dp[j]++;
      }
    }
  }

  let result = -1;
  dp.forEach((el) => {
    if (el > result) {
      result = el;
    }
  });

  console.log(result);
}


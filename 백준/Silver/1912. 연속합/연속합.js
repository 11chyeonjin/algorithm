const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let num = 0;
let arr = [];

rl.on("line", (line) => {
  if (num == 0) {
    num = parseInt(line);
  } else {
    arr = line.split(' ').map((el) => parseInt(el));
    solution();
    rl.close();
  }
});

function solution() {
  let dp = [arr[0]];

  for (let i = 1; i < arr.length; i++) {
    dp[i] = Math.max(arr[i], arr[i] + dp[i - 1]);
  }

  console.log(Math.max(...dp));
}
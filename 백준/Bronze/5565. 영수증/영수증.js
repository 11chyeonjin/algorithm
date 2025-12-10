const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line);
  input.map(Number);
}).on("close", function () {
  let ans = input[0];
  for (let i = 1; i < input.length; i++) {
    ans -= input[i];
  }
  console.log(ans);
});

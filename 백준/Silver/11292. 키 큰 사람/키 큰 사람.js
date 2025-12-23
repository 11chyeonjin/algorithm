const rl = require("readline").createInterface({
  input: process.stdin,
  output: process.stdout,
});

const input = [];

rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  let i = 0;
  while (i < input.length - 1) {
    const ans = solution(input.slice(i + 1, i + 1 + Number(input[i])));
    i += Number(input[i]) + 1;
    console.log(ans);
  }
  process.exit();
});

function solution(arr) {
  arr = arr.map((e) => {
    const [n, h] = e.split(" ");
    return [Number(h), n];
  });

  arr.sort((a, b) => b[0] - a[0]);

  const max = arr[0][0];

  return arr
    .filter(([h, n]) => {
      return h === max;
    })
    .map(([h, n]) => n)
    .join(" ");
}
